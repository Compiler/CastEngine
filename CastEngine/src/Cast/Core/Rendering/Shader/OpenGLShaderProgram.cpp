#include "OpenGLShaderProgram.h"


namespace Cast{


    uint32_t OpenGLShaderProgram::_loadShader(const char* fileName, int type){
        uint32_t shaderID;
		CAST_LOG("Sending to parser");
		const char* shaderSrcChar = ShaderParser::getShaderSource(fileName);
		CAST_LOG("Done parsing");
        shaderID = glCreateShader(type);
		glShaderSource(shaderID, 1, &shaderSrcChar, NULL);
		glCompileShader(shaderID);
		{
			int  success;
			char infoLog[512];
			glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
			if(!success){
				glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
                std::string shaderType;
                if(type == GL_VERTEX_SHADER) shaderType = "VERTEX";
                else if(type == GL_FRAGMENT_SHADER) shaderType = "FRAGMENT";
                else if(type == GL_GEOMETRY_SHADER) shaderType = "GEOMETRY";
                else{
					CAST_ERROR("SHADER::{} TYPE_UNKNOWN - TYPE = {}", shaderType.c_str(), type);
				}
				CAST_ERROR("SHADER::{} COMPILATION FAILED - TYPE = {}", shaderType.c_str(), type);
			}
		}

        return shaderID;

    }

    void OpenGLShaderProgram::loadShader(const char* vertexFile, const char* fragmentFile){
		CAST_LOG("Loading shaders: {}, {}", vertexFile, fragmentFile);
        uint32_t vid = _loadShader(vertexFile, SHADER_TYPE_VERTEX);
        uint32_t fid = _loadShader(fragmentFile, SHADER_TYPE_FRAGMENT);


        _shaderProgram = glCreateProgram();

		glAttachShader(_shaderProgram, vid);
		glAttachShader(_shaderProgram, fid);
		glLinkProgram(_shaderProgram);

		{
			int  success;
			char infoLog[512];
			glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &success);
			if(!success) {
				glGetProgramInfoLog(_shaderProgram, 512, NULL, infoLog);
				CAST_ERROR("CAST_ERROR::SHADER::COMP::LINKING_FAILED\t{}", infoLog);
				assert(false);
			}
		}


		CAST_LOG("Loaded Shader '{}' and '{}'", vertexFile, fragmentFile);

    }


    void OpenGLShaderProgram::uniform_set1Integer(const char* name, int32_t value, bool print){
        int id = _check_uniform_(name, print);
        glUniform1i(id, value);
        GLenum error = glGetError();
		if(error != GL_NO_ERROR){
			CAST_ERROR("OpenGL Error 'uniform_set1Integer' : {}", error);
		}
        
    }

    void OpenGLShaderProgram::uniform_set1Float(const char* name, float value){
  		int id = _check_uniform_(name, true);
        glUniform1fv(id, 1, &value);
        GLenum error = glGetError();
		if(error != GL_NO_ERROR){
			CAST_ERROR("OpenGL Error 'uniform_set1float' : {}", error);
		}

	}

	void OpenGLShaderProgram::uniform_set1Mat4(const char* name, const float* value){
  		int id = _check_uniform_(name, false);
        glUniformMatrix4fv(id, 1, GL_FALSE, value);
        GLenum error = glGetError();
		if(error != GL_NO_ERROR){
			CAST_ERROR("OpenGL Error 'uniform_set1Mat4' : {}", error);
		}

	}



}