#!/bin/bash

cd ./networking_library
./clean.sh
cd ..

exec 2>/dev/null

rm -r build
rm -r lib
rm -r bin
rm -r test/build

