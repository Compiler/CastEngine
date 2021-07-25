echo "linux build"
python populate_cmake_src_deps.py
if [ -d "build" ] 
then
    echo "Build exists" 
else
    mkdir build
fi
cd build
cmake ..
make
./CastEngine_Driver