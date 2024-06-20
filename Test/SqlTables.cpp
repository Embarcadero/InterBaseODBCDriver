/*
 * SQLTables.cpp  
 * Obtained from https://learn.microsoft.com/en-us/sql/odbc/reference/syntax/sqltables-function?view=sql-server-ver16 sample
 *
 * 19-Jun-2024: Contribution by Embarcadero Technologies Inc.
 *              Changes for InterBase ODBC driver.
 *              Modified to add a list of commands that can be executed for various 
 *              filters against SQLTables()
 */

#include <stdio.h>
#include <stdlib.h>
#include "Odbc.h"
#include "Print.h"

#ifdef _WINDOWS
// compile with: user32.lib odbc32.lib  
#include <windows.h>  
#include <sqlext.h>  
#include <strsafe.h>  
#endif
  
// Additional TABLE_TYPE filter input; some predefined ones with SQL_ALL_xyz available below
#define MY_ALL_SYSTEM_TABLES	"SYSTEM TABLE"
#define MY_ALL_USER_TABLES		"TABLE, VIEW"

// List of SQLTables commands to execute
// Command args: description, catalog name, schema name, table name, table type
char *command0[] = {"List of SCHEMA names only", NULL, SQL_ALL_SCHEMAS, NULL, NULL};
char *command1[] = {"List of TABLE_TYPE values only", NULL, NULL, NULL, SQL_ALL_TABLE_TYPES};
char *command2[] = {"List of SYSTEM tables only", NULL, NULL, NULL, MY_ALL_SYSTEM_TABLES};
char *command3[] = {"List of tables including SYSTEM TABLE, TABLE, VIEW", NULL, NULL, NULL, NULL};
char *command4[] = {"List of user tables only, including TABLE, VIEW", NULL, NULL, NULL, MY_ALL_USER_TABLES};
char *command5[] = {"List of Performance Monitoring tables with 'TMP$%' pattern", NULL, NULL, "TMP$%", NULL};
// Catalog pattern commands
char *cat_command0[] = {"List of catalogs, a.k.a SQL_ALL_CATALOGS. return data source name", SQL_ALL_CATALOGS, NULL, NULL, NULL};
char *cat_command1[] = {"INTB-3407: only catalog name with '%' pattern; Same result as SQL_ALL_CATALOGS", "%", NULL, NULL, NULL};
char *cat_command2[] = {"INTB-3407: catalog and schema with '%' pattern, and table name with 'TMP$%' pattern. catalog should be ignored.", "%", "%", "TMP$%", NULL};
char *cat_command3[] = {"INTB-3407: catalog with '%' pattern, and table name with 'TMP$%' pattern. catalog should be ignored.", "%", NULL, "TMP$%", NULL};


// simple helper functions  
int my_SQLSuccessStatus(SQLRETURN rc) {  
   return (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO);  
}  
  
struct DataBinding {  
   SQLSMALLINT TargetType;  
   SQLPOINTER TargetValuePtr;  
   SQLINTEGER BufferLength;  
   SQLLEN StrLen_or_Ind;  
};  
  
void printCatalog(const struct DataBinding* catalogResult, bool print_cat_col) {  
   // Catalog name, if any.
   if (print_cat_col == true) {
       if (catalogResult[0].StrLen_or_Ind != SQL_NULL_DATA)   
	  printf("%-34s", (char *)catalogResult[0].TargetValuePtr);  
       else
	  printf("%-34s", "<null>");
   }
   // Schema name, if any.
   if (catalogResult[1].StrLen_or_Ind != SQL_NULL_DATA)   
      printf("%-34s", (char *)catalogResult[1].TargetValuePtr);  
   else
      printf("%-34s", "<null>");
   // Table name
   if (catalogResult[2].StrLen_or_Ind != SQL_NULL_DATA)   
      printf("%-34s", (char *)catalogResult[2].TargetValuePtr);  
   else
      printf("%-34s", "<null>");
   // Table Type
   if (catalogResult[3].StrLen_or_Ind != SQL_NULL_DATA)   
      printf("%-16s", (char *)catalogResult[3].TargetValuePtr);  
   else
      printf("%-16s", "<null>");
   /* No Remarks
   if (catalogResult[4].StrLen_or_Ind != SQL_NULL_DATA)   
      printf("Remarks = %s\n", (char *)catalogResult[4].TargetValuePtr);  
   */
   printf ("\n");
}  
  
void execute_command (SQLHSTMT hstmt, struct DataBinding *catalogResult, char **command, bool print_cat_col)
{
   SQLRETURN retCode;  

   printf( "\n\n*** %s ***\n", command[0]);
   retCode = SQLTables (hstmt, 
	 /* catalog    */ (SQLCHAR*) command[1], (command[1]) ? strlen (command[1]) : SQL_NTS,
	 /* schema     */ (SQLCHAR*) command[2], (command[2]) ? strlen (command[2]) : SQL_NTS,
	 /* table name */ (SQLCHAR*) command[3], (command[3]) ? strlen (command[3]) : SQL_NTS,
	 /* table type */ (SQLCHAR*) command[4], (command[4]) ? strlen (command[4]) : SQL_NTS);
   
   if (print_cat_col == true) {
       printf ("\n%-34s%-34s%-34s%-16s\n", "Catalog name", "Schema name", "Table name", "Table Type");
       printf ("%.*s\n", 118, "==========================================================================================================");
   } else {
       printf ("\n%-34s%-34s%-16s\n", "Schema name", "Table name", "Table Type");
       printf ("%.*s\n", 84, "==========================================================================================================");
   }
   for ( retCode = SQLFetch(hstmt) ;  my_SQLSuccessStatus(retCode) ; retCode = SQLFetch(hstmt) )  
      printCatalog( catalogResult, print_cat_col );  
   retCode = SQLFreeStmt(hstmt, SQL_CLOSE);
}

// remember to disconnect and free memory, and free statements and handles  
int main() {  
   int bufferSize = 1024, i, numCols = 5;  
   struct DataBinding* catalogResult = (struct DataBinding*) malloc( numCols * sizeof(struct DataBinding) );  
   char* dbName = (char *)malloc( sizeof(char)*bufferSize );  
   char* userName = (char *)malloc( sizeof(char)*bufferSize );  
   char *connectString = "DSN=TestInterBaseConnection";
  
   // declare and initialize the environment, connection, statement handles  
   SQLHENV henv = NULL;   // Environment     
   SQLHDBC hdbc = NULL;   // Connection handle  
   SQLHSTMT hstmt = NULL;   // Statement handle  
  
   SQLRETURN retCode;  
#ifdef _WINDOWS
   HWND desktopHandle = GetDesktopWindow();   // desktop's window handle  
#else
   SQLHWND desktopHandle;
#endif
   SQLWCHAR connStrbuffer[1024];  
   SQLSMALLINT connStrBufferLen;  
  
   retCode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);  
   retCode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, -1);  
   retCode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);  
   retCode = SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER)10, 0);  
   //retCode = SQLDriverConnect(hdbc, desktopHandle, (SQLCHAR*)"Driver={SQL Server}", SQL_NTS, (SQLCHAR*)connStrbuffer, 1024 + 1, &connStrBufferLen, SQL_DRIVER_PROMPT);  
   retCode = SQLDriverConnect(hdbc, desktopHandle, (SQLCHAR*)connectString, SQL_NTS, (SQLCHAR*)connStrbuffer, 1024 + 1, &connStrBufferLen, SQL_DRIVER_PROMPT);  
   retCode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);  
   retCode = SQLGetInfo(hdbc, SQL_DATABASE_NAME, dbName, (SQLSMALLINT)bufferSize, (SQLSMALLINT *)&bufferSize);  
   retCode = SQLGetInfo(hdbc, SQL_USER_NAME, userName, (SQLSMALLINT)bufferSize, (SQLSMALLINT *)&bufferSize);  
  
   bufferSize = 1024;  
  
   // allocate memory for the binding  
   // free this memory when done  
   for ( i = 0 ; i < numCols ; i++ ) {  
      catalogResult[i].TargetType = SQL_C_CHAR;  
      catalogResult[i].BufferLength = (bufferSize + 1);  
      catalogResult[i].TargetValuePtr = malloc( sizeof(unsigned char)*catalogResult[i].BufferLength );  
   }  
  
   // setup the binding (can be used even if the statement is closed by closeStatementHandle)  
   for ( i = 0 ; i < numCols ; i++ )  
      retCode = SQLBindCol(hstmt, (SQLUSMALLINT)i + 1, catalogResult[i].TargetType, catalogResult[i].TargetValuePtr, catalogResult[i].BufferLength, &(catalogResult[i].StrLen_or_Ind));  
  
   execute_command (hstmt, catalogResult, command0, false);
   execute_command (hstmt, catalogResult, command1, false);
   execute_command (hstmt, catalogResult, command2, false);
   execute_command (hstmt, catalogResult, command3, false);
   execute_command (hstmt, catalogResult, command4, false);
   execute_command (hstmt, catalogResult, command5, false);

   // INTB-3407: Get tables from all catalogs, aka. "%" pattern
   execute_command (hstmt, catalogResult, cat_command0, true);
   execute_command (hstmt, catalogResult, cat_command1, true);
   execute_command (hstmt, catalogResult, cat_command2, false);
   execute_command (hstmt, catalogResult, cat_command3, false);

}

