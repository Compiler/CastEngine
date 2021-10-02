#include "OpenGLRenderer.h"

namespace Cast{

    OpenGLRenderer::OpenGLRenderer():Renderer(), _layout({VAOElement(4), VAOElement(4)}){ 
        _vao.setLayout(std::move(_layout));
    }


    void OpenGLRenderer::SetShader(const char* name, std::initializer_list<Shader> shaders){
        CAST_LOG("Setting shader to ");
        std::string shader_key = "";
        for(auto shader : shaders){
            CAST_LOG("{}", shader.filePath);
            shader_key += std::to_string((int)shader.type) + shader.filePath;
        }

        if(_shaderMap.find(shader_key) == _shaderMap.end()){
            CAST_LOG("New shader set, compiling and setting {}", shader_key);
            OpenGLShaderProgram program;
            for(auto shader : shaders){
                program.loadShader(shader.filePath, shader.type);
            }
            program.compile();
            _shaderMap.emplace(shader_key, std::move(program));
            _shaderMapNamed.emplace(name, shader_key);
            
        }
    }


    
    void OpenGLRenderer::clearColor(float r, float g, float b, float a){
        glClearColor(r,g,b,a);
    }
    void OpenGLRenderer::clearColorBit(){
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void OpenGLRenderer::clearDepthBit(){
        glClear(GL_DEPTH_BUFFER_BIT);
    }


    void OpenGLRenderer::Draw(){
        _buffer.setVertices(std::move(m_vertices));
        _buffer.init();
        _vao.init();
        glDrawArrays(GL_TRIANGLES, 0, 100);


        
    }
    void OpenGLRenderer::SubmitTriangle(float bottomLeftX, float bottomLeftY, float size){
        this->m_vertices.push_back(bottomLeftX);
        this->m_vertices.push_back(bottomLeftY);
        this->m_vertices.push_back(1);
        this->m_vertices.push_back(1);
        //default color red
        this->m_vertices.insert(this->m_vertices.end(), {1,0,1,1});

        this->m_vertices.push_back(bottomLeftX + size);
        this->m_vertices.push_back(bottomLeftY);
        this->m_vertices.push_back(1);
        this->m_vertices.push_back(1);

        this->m_vertices.insert(this->m_vertices.end(), {1,0,1,1});

        this->m_vertices.push_back(bottomLeftX + size / 2.0);
        this->m_vertices.push_back(bottomLeftY + size);
        this->m_vertices.push_back(1);
        this->m_vertices.push_back(1);
        
        this->m_vertices.insert(this->m_vertices.end(), {1,0,1,1});
        
    }
     
    void OpenGLRenderer::SubmitTriangle(glm::vec3 vertices[3], glm::vec3 color[3]){
        this->m_vertices.push_back(vertices[0].x);
        this->m_vertices.push_back(vertices[0].y);
        this->m_vertices.push_back(vertices[0].z);
        this->m_vertices.push_back(1);
        this->m_vertices.push_back(color[0].x);
        this->m_vertices.push_back(color[0].y);
        this->m_vertices.push_back(color[0].z);
        this->m_vertices.push_back(1);
        this->m_vertices.push_back(vertices[1].x);
        this->m_vertices.push_back(vertices[1].y);
        this->m_vertices.push_back(vertices[1].z);
        this->m_vertices.push_back(1);
        this->m_vertices.push_back(color[1].x);
        this->m_vertices.push_back(color[1].y);
        this->m_vertices.push_back(color[1].z);
        this->m_vertices.push_back(1);
        this->m_vertices.push_back(vertices[2].x);
        this->m_vertices.push_back(vertices[2].y);
        this->m_vertices.push_back(vertices[2].z);
        this->m_vertices.push_back(1);
        this->m_vertices.push_back(color[2].x);
        this->m_vertices.push_back(color[2].y);
        this->m_vertices.push_back(color[2].z);
        this->m_vertices.push_back(1);

    }


    OpenGLRenderer::~OpenGLRenderer(){}


}