#!/bin/bash

./networking_library/build_and_test.sh

echo "BUILDING GAME NETWORKING LIBRARY"
cd build || mkdir build && cd build

cmake .. || { echo 'CMAKE FAILED' ; exit 1; }
make || { echo 'MAKE failed' ; exit 1; }
#../bin/networking || { echo 'PROGRAM failed' ; exit 1; }


