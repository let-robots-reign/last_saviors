cd build || mkdir build && cd build

cmake .. || { echo 'CMAKE FAILED' ; exit 1; }
make || { echo 'MAKE failed' ; exit 1; }
#../bin/networking || { echo 'PROGRAM failed' ; exit 1; }

#cd ../test
#cd build || mkdir build && cd build
#cmake .. || { echo 'CMAKE failed' ; exit 1; }
#make || { echo 'MAKE failed' ; exit 1; }
#./networking_unit_tests || { echo 'TESTS failed' ; exit 1; }

