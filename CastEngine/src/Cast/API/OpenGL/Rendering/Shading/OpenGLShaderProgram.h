#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdint.h>
#include <string>
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Rendering/Shader/ShaderProgram.h>
#include <Cast/Core/Rendering/Shader/ShaderParser.h>
#include <Cast/Core/Rendering/Shader/Shader.h>


#define SHADER_TYPE_VERTEX      (int) 0x8B31
#define SHADER_TYPE_FRAGMENT    (int) 0x8B30
#define SHADER_TYPE_GEOMETRY    (int) 0x8DD9
#define SHADER_TYPE_TESSELATION (uint8_t)GL_arb_tesselation_shader

#ifdef CAST_DEBUG_MODE
#define CAST_CHECK_CALL(name, ...) _check_uniform_(name); 
#endif

namespace Cast{

    class OpenGLShaderProgram : public ShaderProgram{
        
        private:
            uint32_t _getOpenGLValForShaderType(Shader::ShaderType type);
            uint32_t _loadShader(const char* fileName, Shader::ShaderType type);
            uint32_t _shaderProgram;
            std::vector<uint32_t> _shaderIDs;

            inline int _check_uniform_(const char* name, bool print = true){
                GLint uniformID = glGetUniformLocation(_shaderProgram, name);
                if(uniformID == -1 && print){
                    CAST_WARN("'{}' name not found in shader.", name);
                }
                return uniformID;
            }
        public:
            OpenGLShaderProgram() = default;

            void loadShader(const char* shaderFilePath, Shader::ShaderType type);
            void loadShader(std::initializer_list<Shader> shaders);
            void compile();
            
            void use(){glUseProgram(_shaderProgram);}


            void uniform_set1Integer(const char* name, int32_t value, bool print = true);
            void uniform_set1Float(const char* name, float value);
            void uniform_set1Mat4(const char* name, const float* value);

            ~OpenGLShaderProgram(){}

    };



}