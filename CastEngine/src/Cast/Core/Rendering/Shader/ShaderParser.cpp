#include "ShaderParser.h"

namespace Cast{

    std::string ShaderParser::getShaderSource(const char* filePath){
		std::string shaderSrc;
		FileLoaderFactory::loadTextFromFile(filePath, shaderSrc);
        std::size_t location = shaderSrc.find("#include");
        while(location != std::string::npos){
            std::size_t start = shaderSrc.find("\"", location);
            std::size_t end = shaderSrc.find("\"", start+1);
            std::string include = shaderSrc.substr(start + 1, (end - start - 1));

		    std::string appendedShaderSrc;
            std::string appendFileLocation = CAST_INTERNAL_SHADER("") + include;
		    FileLoaderFactory::loadTextFromFile(appendFileLocation.c_str(), appendedShaderSrc);

            shaderSrc = shaderSrc.substr(0, location) + appendedShaderSrc + shaderSrc.substr(end+1);


            location = shaderSrc.find("#include");
            
        }
        return shaderSrc;

    }

    std::vector<uint32_t> ShaderParser::compileGLSLToSPRV(const char* fileName, const char* outputName, Shader::ShaderType type){



        if(!std::filesystem::exists(fileName)){
            CAST_ERROR("Error: The file '{}' does not exist", fileName);
            return {};
        }

        CAST_LOG("Compiling '{}' to '{}'", fileName, outputName);
        std::string preface = std::string(CAST_INTERNAL_SHADER("")) + std::string(outputName);
        if(std::filesystem::exists(preface)){

            CAST_WARN("'{}' already exists, checking return date.", preface.c_str());
            auto file_last_write = std::filesystem::last_write_time(fileName);
            auto output_last_write = std::filesystem::last_write_time(preface);
            if(file_last_write <= output_last_write){
                CAST_LOG("Loading old spv");
                std::vector<char> char_vec = FileLoaderFactory::readSPV(preface.c_str());
                const uint32_t* casted = reinterpret_cast<const uint32_t*>(char_vec.data());
                // std::vector<uint32_t> return_vec = {};
                // for(int i = 0; i < char_vec.size();i ++){
                //     return_vec.push_back(*(casted + i));
                // }
                return {casted, casted + char_vec.size()}; // this return the implicit type from return statement of the casted pointer
            }

        }
        CAST_LOG("File contents newer than spv, recompiling.");
        std::string shaderSrc, errorSrc;
		FileLoaderFactory::loadTextFromFile(fileName, shaderSrc);
        shaderc_shader_kind kind = castTypeToShaderCKind(type);
        CAST_LOG("Compiling glsl");
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
        std::ofstream fout(preface, std::ios::out | std::ios::binary);
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