#!/bin/bash

echo ''
echo 'TESTING GAME NETWORKING LIBRARY'

cd test
cd build || mkdir build && cd build
cmake .. || { echo 'CMAKE FAILED' ; exit 1; }
make || { echo 'MAKE failed' ; exit 1; }
./networking_tests || { echo 'TESTS failed' ; exit 1; }
cd ../..
