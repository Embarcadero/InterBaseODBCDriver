
net use

SET PATH=C:\Program Files (x86)\MSBuild\12.0\bin;%PATH%

msbuild /p:Platform="Win32" /p:Configuration=Release odbcib.sln /t:clean
msbuild /p:Platform="Win32" /p:Configuration=Release odbcib.sln

msbuild /p:Platform="x64" /p:Configuration=Release odbcib.sln /t:clean
msbuild /p:Platform="x64" /p:Configuration=Release odbcib.sln

echo Copying files to network file share locations...
@echo ON
copy  Win32\Release\OdbcIB.dll T:\odbc\
copy  x64\Release\OdbcIB.dll T:\odbc\x64

