
net use

C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\msbuild /p:Platform="Win32" /p:Configuration=Release odbcib.sln

C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\msbuild /p:Platform="x64" /p:Configuration=Release odbcib.sln

copy  Win32\Release\OdbcIB.dll T:\odbc\

copy  x64\Release\OdbcIB.dll T:\odbc\x64

