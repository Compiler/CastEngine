#pragma once
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Utils/Files/FileLoaderFactory.h>
#include <vector>

namespace Cast{

    class ShaderParser{
        public:
            static const char* getShaderSource(const char* filePath);

    };

}