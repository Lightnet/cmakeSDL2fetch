@echo off
:: Create a build directory
mkdir build 
:: Build from that directory so the build files are in one place
cd build && cmake ..
:: test config
::cmake -D ISTEST=ON | OFF
::cmake -D ISTEST=ON . 
:: Build the project
cmake --build . 
pause