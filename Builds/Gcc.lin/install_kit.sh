#!/bin/sh
#
# Helper script to install the just built ODBC kit on the develper's machine
# for further testing.
#

set -x

rm -rf test
mkdir test
cp OdbcIB-1.0.0.107.tar.gz test
cd test
gunzip OdbcIB-1.0.0.107.tar.gz
tar -xvf OdbcIB-1.0.0.107.tar
sudo ./install.sh

