#!/bin/sh

set -x

rm -rf test
mkdir test
cp OdbcIB-1.0.0.107.tar.gz test
cd test
gunzip OdbcIB-1.0.0.107.tar.gz
tar -xvf OdbcIB-1.0.0.107.tar
#sudo -E ./install.sh --verbose --test --createTestDSN
sudo -E ./install.sh --verbose --createTestDSN

