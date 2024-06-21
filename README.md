# InterBaseODBCDriver
An ODBC driver for the InterBase database

Install kit for InterBase ODBC driver on Windows is included in your Embarcadero InterBase 2020 product.

How to build from sources?
  Windows (32bit and 64bit): Sample build projects and scripts are available. See Builds/MsVc120.win for building with Visual Studio 2013. You can also run the script odbcbuild.bat in that folder.
  Linux (x86_64): Readme and makefile are available at Builds/Gcc.lin directory. Makefile is named makefile.linux
  macOS (arm64): Readme and makefile are available at Builds/darwin directory. Makefile is named makefile.darwin

Testing your builds?
  There are a bunch of test modules under the Test/ folder. Most of these use some Windows specific APIs.
  Windows: Test/Test.sln (Visual Studio 2013)
  Linux (x86_64): Test/makefile.linux
         make -f makefile.linux all
  macOS (arm64): Test/makefile.darwin
         make -f makefile.darwin all

