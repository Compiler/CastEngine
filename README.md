# CastEngine

## Building Windows

### MINGW
- Make sure you are using MinGW64-bit
- Rename C:/MinGW64/bin/mingw32-make.exe -> C:/MinGW64/bin/make.exe
- Clone the repo and include the submodules
- Add MinGW64 binaries to your environment variables into the path
- ```> git clone --recurse-submodules -j8 git@github.com:Compiler/CastEngine.git```
- ```> make```

### MSYS2
- Download and install the installer from https://www.msys2.org/
  - Run ```pacman -Syu```
  - Reopen terminal and Run ```pacman -Su```
  - Run ```pacman -S --needed base-devel mingw-w64-x86_64-toolchain```
- Rename C:/msys64/mingw64/bin/mingw32-make.exe -> C:/msys64/mingw64/bin/make.exe


## Building your own GLSLC Binaries
- Clone GLSLC from https://github.com/google/shaderc
- Clone SPIR-V Tools into the shaderc/third_party folder: https://github.com/KhronosGroup/SPIRV-Tools
- Then go into the SPIR-V Tools folder located under shaderc/third_party/SPIR-V-Tools
- Go into SPIR-V-Tools/external and clone SPIR-V-Headers: https://github.com/KhronosGroup/SPIRV-Headers
- Now cd to the root of shaderc and run
  - ``` > cmake . -DSHADERC_SKIP_TESTS=true```
  - Then you run ``` cmake --build . --config Release ```
- Now the binaries for shaderc are under shaderc/libshaderc/Release


## Building in Ubuntu
- Make sure you have the correct tools
  - Cmake, make
  - sudo apt-get install build-essential manpages-dev
  - sudo apt-get install mesa-utils
  - sudo apt-get install libgl1-mesa-dev
  - sudo apt-get install xorg-dev libglu1-mesa-dev
  - Install the vulkan sdk
- run: ```export VULKAN_SDK=``` and put your path to the parent of the bin folder
