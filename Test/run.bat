REM Following build command for use with Visual Studio 2005
rem cl Test.cpp Print.cpp Odbc.cpp JString.cpp /FeTest.exe -I..\IscDbc -IC:"\Program Files\Embarcadero\InterBase\gds_db\SDK\include" -Ic:"\Program Files (x86)\Windows Kits\8.0\Include\um" /EHsc /Zi

REM Following build command for use with Visual Studio 2013
REM It required the installation of MBCS support for MFC 
REM    from https://www.microsoft.com/en-us/download/confirmation.aspx?id=40770
SET INCLUDE_IB=-I..\IscDbc -IC:"\Program Files\Embarcadero\InterBase_ib2020\SDK\include"
SET INCLUDE_SYS=-Ic:"\Program Files (x86)\Windows Kits\8.1\Include\um"
SET INCLUDE_PATHS=%INCLUDE_IB% %INCLUDE_SYS%
SET CL_OPTS=/D_WIN32_WINNT=0x0502 /DWIN32_LEAN_AND_MEAN /EHsc /Zi

cl Test.cpp Print.cpp Odbc.cpp JString.cpp %INCLUDE_PATHS% %CL_OPTS% /FeTest.exe 
cl SimpleTest.cpp Print.cpp Odbc.cpp JString.cpp %INCLUDE_PATHS% %CL_OPTS% /FeSimpleTest.exe 
