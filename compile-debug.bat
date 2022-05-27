@echo off
cd %CD%\src
cmake ../CMakeLists.txt -DCMAKE_CXX_COMPILER=g++ -DCMAKE_CC_COMPILER=gcc
cmake --build ..
cd ../
