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


}