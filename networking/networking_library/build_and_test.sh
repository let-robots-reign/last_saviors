#!/bin/bash

echo "BUILDING NETWORKING LIBRARY"
cd build || mkdir build && cd build

cmake .. || { echo 'CMAKE FAILED' ; exit 1; }
make || { echo 'MAKE failed' ; exit 1; }

