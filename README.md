# InterBaseODBCDriver
An ODBC driver for the InterBase database

Install kit for InterBase ODBC driver on Windows is included in your Embarcadero InterBase 2020 product.

## How to build from sources?
  * Windows (32bit and 64bit): Sample build projects and scripts are available. For building with Visual Studio 2013, go to folder [Builds/MsVc120.win](Builds/MsVc120.win) . You can also run the script [odbcbuild.bat](Builds/MsVc120.win/odbcbuild.bat) in that folder.
  * Linux (x86_64): Readme and makefile are available at [Builds/Gcc.lin](Builds/Gcc.lin). Makefile is named [makefile.linux](Builds/Gcc.lin/makefile.linux)
  * macOS (arm64): Readme and makefile are available at [Builds/darwin](Builds/darwin). Makefile is named [makefile.darwin](Builds/darwin/makefile.darwin)

## Testing your builds?
  There are a bunch of test modules under the [Test](Test) folder. Most of these use some Windows specific APIs.
  * Windows: [Test/Test.sln](Test/Test.sln) (Visual Studio 2013)
  * Linux (x86_64): [Test/makefile.linux](Test/makefile.linux)
    - make -f makefile.linux all
  * macOS (arm64): [Test/makefile.darwin](Test/makefile.darwin)
    - make -f makefile.darwin all

