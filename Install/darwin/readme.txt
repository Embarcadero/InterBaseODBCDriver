InterBase ODBC Driver For macOS/darwin
======================================

This is the latest version of the InterBase ODBC 
driver for InterBase. See 
WhatsNew.txt for details of changes.


Requirements
------------

This driver has been compiled to use the unixODBC 
libraries. You must install the core unixODBC 
libraries in order to be able to use this driver 
on your macOS/darwin distribution. The unixODBC 
development library and the unixODBC GUI tools
are optional.


Installation
------------

Run install.sh. This script will untar the libraries 
to /usr/local/lib. It will also install the documentation 
into the standard documentation location for your 
distribution.

You can run ./install.sh --help for more information
on installation options.


Configuration
-------------

The install script will attempt to automatically register 
the driver. You also have the option of configuring a test
dsn by passing the parameter --createTestDSN to install.sh.


Documentation
-------------

Be sure to read the release notes. They are available in the 
FirebirdODBC directory in the standard documentation location
for your distribution. You will also find detailed information 
in the html sub-dir.


Known issues
------------

If you receive an error such as this:

  IscDbc: cannot open shared object file: No such file or directory
  
you need to set LD_LIBRARY_PATH. This can be done temporarily 
by setting the environment before calling your application:

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib/unixODBC myODBCApp


Uninstallation
--------------

The installation procedure will create uninstall.sh in the
documentation directory. 


Bug Reports
-----------

If you think you have found a bug, please log it at 
https://github.com/Embarcadero/InterBaseODBCDriver/issues 


