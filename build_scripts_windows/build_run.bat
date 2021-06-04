python auto_file_cmake.py
if not exist "build" mkdir build
cd build
cmake -G "MinGW Makefiles" ..
make
CastDriver.exe