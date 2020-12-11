#!/bin/bash

cd ./networking_library
#$(./build_and_test.sh) || { echo 'NETWORKING LIBRARY FAILED' ; exit 1; }
./build_and_test.sh
cd ..

echo ''
echo 'BUILDING GAME NETWORKING LIBRARY'
cd build || mkdir build && cd build

cmake .. || { echo 'CMAKE FAILED' ; exit 1; }
make || { echo 'MAKE failed' ; exit 1; }

cd ../test
cd build || mkdir build && cd build
cmake .. || { echo 'CMAKE FAILED' ; exit 1; }
make || { echo 'MAKE failed' ; exit 1; }
./game_networking_tests || { echo 'TESTS failed' ; exit 1; }

