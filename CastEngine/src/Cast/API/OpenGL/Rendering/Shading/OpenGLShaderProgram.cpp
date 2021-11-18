#include "OpenGLShaderProgram.h"


namespace Cast{
    uint32_t OpenGLShaderProgram::_getOpenGLValForShaderType(Shader::ShaderType type){
		switch(type){
			case Shader::ShaderType::Vertex:{
				return SHADER_TYPE_VERTEX;
				break;
			}
			case Shader::ShaderType::Fragment:{
				return SHADER_TYPE_FRAGMENT;
				break;
			}
			case Shader::ShaderType::Geometry:{
				return SHADER_TYPE_GEOMETRY;
				break;
			}
			// case Shader::ShaderType::Tesselation:{
			// 	return SHADER_TYPE_TESSELATION;
			// 	break;
			// }
			default:{
				CAST_ERROR("Type doesn't exist");
			}
		}
		return 44;
	}


    uint32_t OpenGLShaderProgram::_loadShader(const char* fileName, Shader::ShaderType type){
        uint32_t shaderID;
		auto shaderSrc = ShaderParser::getShaderSource(fileName);
		const char* shaderSrcChar = shaderSrc.c_str();
		
        shaderID = glCreateShader(_getOpenGLValForShaderType(type));
		glShaderSource(shaderID, 1, &shaderSrcChar, NULL);
		glCompileShader(shaderID);
		int type_val = _getOpenGLValForShaderType(type);
		{
			int  success;
			char infoLog[512];
			glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
			if(!success){
				glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
                std::string shaderType;
                if(type_val == GL_VERTEX_SHADER) shaderType = "VERTEX";
                else if(type_val == GL_FRAGMENT_SHADER) shaderType = "FRAGMENT";
                else if(type_val == GL_GEOMETRY_SHADER) shaderType = "GEOMETRY";
                else{
					CAST_ERROR("SHADER::{} TYPE_UNKNOWN - TYPE = {}", shaderType.c_str(), type);
				}
				CAST_LOG("{}", shaderSrc.c_str());
				CAST_ERROR("SHADER::{} COMPILATION FAILED - TYPE = {}", shaderType.c_str(), type);
			}
		}

        return shaderID;

    }
    void OpenGLShaderProgram::loadShader(const char* shaderFilePath, Shader::ShaderType type){
		_shaderIDs.push_back(_loadShader(shaderFilePath, type));
		CAST_LOG("Loaded Shader '{}'", shaderFilePath);
	}

    void OpenGLShaderProgram::loadShader(std::initializer_list<Shader> shaders){
		for(auto shader : shaders) _shaderIDs.push_back(_loadShader(shader.filePath, shader.type));
	}


	void OpenGLShaderProgram::compile(){
		_shaderProgram = glCreateProgram();
		if(_shaderProgram == 0) {
			CAST_FATAL("Shader program failed to be created");
		}
		for(auto shaderID : _shaderIDs){
			glAttachShader(_shaderProgram, shaderID);
		}
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