::
:: 07-Aug-2012: Contribution by Embarcadero Technologies Inc.
::              Changes for InterBase ODBC driver
::

:BUILD
::========
@call setenvvar.bat %1 %2
@title %BUILDTYPE%  %1%
@echo   %BUILDTYPE% %1%
@set > build_%1%.log

@devenv %~dp0\OdbcIB.sln /%BUILDTYPE% "%BUILDCONFIG%|%FB_TARGET_PLATFORM%" /OUT build_%1%.log 2>&1

:: Now make the packages
pushd ..\..\Install\Win32
@echo Now making packages
call MakePackage.bat
popd


goto :EOF

