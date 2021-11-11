python populate_cmake_src_deps.py
if not exist "build" mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug -G "MinGW Makefiles" ..
make
CastEngine_Driver && cd ../