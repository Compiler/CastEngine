#pragma once
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Utils/Files/FileLoaderFactory.h>
#include <Cast/Core/Rendering/Shader/Shader.h>
#include <vector>
#include <shaderc/shaderc.hpp>
#include <fstream>
#include <filesystem>

namespace Cast{

    class ShaderParser{

        public:
            static const char* getShaderSource(const char* filePath);
            static std::vector<uint32_t> compileGLSLToSPRV(const char* fileName, const char* outputName, Shader::ShaderType type);
            static shaderc_shader_kind castTypeToShaderCKind(Shader::ShaderType type);
    };

}