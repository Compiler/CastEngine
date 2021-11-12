#pragma once
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Utils/Files/FileLoaderFactory.h>
#include <Cast/Core/Rendering/Shader/Shader.h>
#include <vector>
#include <shaderc/shaderc.hpp>
#include <fstream>
#include <filesystem>
#include <iostream>
namespace Cast{

    class ShaderParser{

        public:
            static std::string getShaderSource(const char* filePath);
            static std::vector<uint32_t> compileGLSLToSPRV(const char* fileName, const char* outputName, Shader::ShaderType type);
            static shaderc_shader_kind castTypeToShaderCKind(Shader::ShaderType type);
    };

}