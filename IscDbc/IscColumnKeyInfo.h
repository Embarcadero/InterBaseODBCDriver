/*
 *  
 *     The contents of this file are subject to the Initial 
 *     Developer's Public License Version 1.0 (the "License"); 
 *     you may not use this file except in compliance with the 
 *     License. You may obtain a copy of the License at 
 *     https://www.firebirdsql.org/en/initial-developer-s-public-license-version-1-0/
 *
 *     Software distributed under the License is distributed on 
 *     an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either 
 *     express or implied.  See the License for the specific 
 *     language governing rights and limitations under the License.
 *
 *
 *  The Original Code was created by Vladimir Tsvigun for IBPhoenix.
 *
 *  Copyright (c) 2006 Vladimir Tsvigun
 *  All Rights Reserved.
 */

// IscColumnKeyInfo.h: interface for the IscColumnKeyInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_IscColumnKeyInfo_h_)
#define _IscColumnKeyInfo_h_

#include "IscMetaDataResultSet.h"

namespace IscDbcLibrary {

class IscColumnKeyInfo : public IscMetaDataResultSet  
{
public:
	virtual bool getColumnKeyInfo( const char *tableName, const char *columnName );
	IscColumnKeyInfo( IscDatabaseMetaData *metaData );
};

}; // end namespace IscDbcLibrary

#endif // !defined(_IscColumnKeyInfo_h_)
