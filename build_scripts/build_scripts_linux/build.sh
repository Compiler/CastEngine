echo "linux build"
python populate_cmake_src_deps.py
if [ -d "build" ] 
then
    echo "Build exists" 
else
    echo "Build not there"
    mkdir build
fi
cd build
cmake -j8 -DCMAKE_BUILD_TYPE=Debug ..
make