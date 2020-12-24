#!/bin/bash

cd ./networking_library
#$(./build_and_test.sh) || { echo 'NETWORKING LIBRARY FAILED' ; exit 1; }
./build_and_test.sh
cd ..

./build.sh
#./test.sh

