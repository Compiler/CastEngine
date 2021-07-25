python populate_cmake_src_deps.py
if not exist "build" mkdir build
cd build
cmake -DBUILD_SHARED_LIBS=ON -G "MinGW Makefiles" ..
make
CastEngine_Driver && cd ../