@echo off
cd %CD%\src
cmake ../CMakeLists.txt
cmake --build ..
cd ../