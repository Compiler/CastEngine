#include "ShaderParser.h"

namespace Cast{

    const char* ShaderParser::getShaderSource(const char* filePath){
		std::string shaderSrc;
        CAST_LOG("Parsing: {}", filePath);
		FileLoaderFactory::loadTextFromFile(filePath, shaderSrc);
        std::size_t location = shaderSrc.find("#include");
        while(location != std::string::npos){
            std::size_t start = shaderSrc.find("\"", location);
            std::size_t end = shaderSrc.find("\"", start+1);
            std::string include = shaderSrc.substr(start + 1, (end - start - 1));
            CAST_LOG("Trying to append '{}'", include);

		    std::string appendedShaderSrc;
            std::string appendFileLocation = CAST_INTERNAL_SHADER("") + include;
		    FileLoaderFactory::loadTextFromFile(appendFileLocation.c_str(), appendedShaderSrc);

            shaderSrc = shaderSrc.substr(0, location) + appendedShaderSrc + shaderSrc.substr(end+1);


            location = shaderSrc.find("#include");
            
        }
        return shaderSrc.c_str();

    }


    std::vector<uint32_t> ShaderParser::compileGLSLToSPRV(const char* fileName, const char* outputName, Shader::ShaderType type){
        if(!std::filesystem::exists(fileName)){
            CAST_ERROR("Error: The file '{}' does not exist", fileName);
            return {};
        }
        if(std::filesystem::exists(outputName)){
            CAST_WARN("Not compiling, '{}' already exists!", outputName);
            auto char_vec = FileLoaderFactory::readSPV(outputName);
            return std::vector<uint32_t>{char_vec.begin(), char_vec.end()};
        }
        std::string shaderSrc, errorSrc;
		FileLoaderFactory::loadTextFromFile(fileName, shaderSrc);
        shaderc_shader_kind kind = castTypeToShaderCKind(type);

        shaderc::CompileOptions options{};
        options.SetOptimizationLevel(shaderc_optimization_level_zero);
        options.SetGenerateDebugInfo();

        shaderc::Compiler compiler{};
        shaderc::SpvCompilationResult result = compiler.CompileGlslToSpv(shaderSrc, kind, errorSrc.data(), options);
        
        if(result.GetCompilationStatus() != shaderc_compilation_status_success){
            CAST_FATAL("Error compiling file '{}' glsl to sprv: {}", fileName, result.GetErrorMessage().c_str());
        }

        std::vector<uint32_t> compiler_output = { result.begin(), result.end() };
		compiler_output.resize(compiler_output.size() * (sizeof(uint32_t) / sizeof(char)), 0);

        //write
        std::ofstream fout(outputName, std::ios::out | std::ios::binary);
        fout.write((char*)&compiler_output[0], compiler_output.size());
        fout.close();
        return compiler_output;

    }


    shaderc_shader_kind ShaderParser::castTypeToShaderCKind(Shader::ShaderType type){
        switch(type){
            case Shader::ShaderType::Vertex:{
                return shaderc_shader_kind::shaderc_glsl_default_vertex_shader;
                break;
            }
            case Shader::ShaderType::Fragment:{
                return shaderc_shader_kind::shaderc_glsl_default_fragment_shader;
                break;
            }
            case Shader::ShaderType::Geometry:{
                return shaderc_shader_kind::shaderc_glsl_default_geometry_shader;
                break;
            }
            default:
                CAST_FATAL("Failed to deduce shaderc type");
        }
    }


}