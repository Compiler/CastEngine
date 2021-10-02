#pragma once
#include <Cast/Core/Rendering/Shader/Shader.h>
#include <initializer_list>
namespace Cast{


    class ShaderProgram{

        private:

        public:
            ShaderProgram(){}
            virtual void loadShader(const char* shaderFilePath, Shader::ShaderType shaderType) = 0;
            virtual void loadShader(std::initializer_list<Shader> shaders) = 0;
            virtual void compile() = 0;
            virtual void use() = 0;
            virtual ~ShaderProgram(){}


    };

}