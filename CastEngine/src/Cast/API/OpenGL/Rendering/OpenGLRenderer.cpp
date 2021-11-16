#include "OpenGLRenderer.h"

namespace Cast{

    OpenGLRenderer::OpenGLRenderer():Renderer(), _layout({VAOElement(4), VAOElement(4)}){ 
        glEnable(GL_FRAMEBUFFER_SRGB); //Gamma correct
        _vao.setLayout(std::move(_layout));

        glGenBuffers(1, &_uboBufferID);
        
        glBindBuffer(GL_UNIFORM_BUFFER, _uboBufferID);
        glBufferData(GL_UNIFORM_BUFFER, sizeof(UniformBufferObject), NULL, GL_STATIC_DRAW);
        glBindBuffer(GL_UNIFORM_BUFFER, 0);
        Camera cam{};
        cam.init(1920, 1080);
        cam.ubo.proj[0][0] *= -1;
        glBindBufferRange(GL_UNIFORM_BUFFER, 0, _uboBufferID, 0, sizeof(UniformBufferObject));
        glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(cam.ubo.model));
        glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(cam.ubo.view));
        glBufferSubData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(cam.ubo.proj));

    }


    void OpenGLRenderer::CreateShader(const char* name, std::initializer_list<Shader> shaders){
        CAST_LOG("Setting shader to ");
        std::string shader_key = "";
        for(auto shader : shaders){
            CAST_LOG("{}", shader.filePath);
            shader_key += std::to_string((int)shader.type) + shader.filePath;
        }

        if(_shaderMap.find(shader_key) == _shaderMap.end()){
            CAST_LOG("New shader set, compiling and setting {}", shader_key);
            OpenGLShaderProgram program = OpenGLShaderProgram();
            unsigned int uniformBlockIndex = glGetUniformBlockIndex(program.getProgramID(), "UniformBufferObject");
            glUniformBlockBinding(program.getProgramID(), uniformBlockIndex, 0);

            for(auto shader : shaders){
                program.loadShader(shader.filePath, shader.type);
            }
            program.compile();
            _shaderMap.emplace(shader_key, program);
            _shaderMapNamed.emplace(name, shader_key);
            
        }
    }


    
    void OpenGLRenderer::clearColor(float r, float g, float b, float a){
        glClearColor(r,g,b,a);
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);
    }
    void OpenGLRenderer::clearColorBit(){
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void OpenGLRenderer::clearDepthBit(){
        glClear(GL_DEPTH_BUFFER_BIT);
    }


    void OpenGLRenderer::Draw(){
        int draw_size = m_vertices.size();
        _buffer.setVertices(std::move(m_vertices));
        _buffer.init();
        _vao.init();
        glDrawArrays(GL_TRIANGLES, 0, draw_size);

        
    }




    void OpenGLRenderer::SubmitVertexBuffer(const std::vector<VertexTemplate>& buffer){
        for(const auto& vertex : buffer){
            this->m_vertices.insert(this->m_vertices.end(), {vertex.position.x, vertex.position.y, vertex.position.z, vertex.position.w, vertex.color.x, vertex.color.y, vertex.color.z, vertex.color.w });
        }
    }
    void OpenGLRenderer::SubmitTriangle(float bottomLeftX, float bottomLeftY, float size){
        this->m_vertices.push_back(bottomLeftX);
        this->m_vertices.push_back(bottomLeftY);
        this->m_vertices.push_back(1);
        this->m_vertices.push_back(1);
        //default color pink
        this->m_vertices.insert(this->m_vertices.end(), {m_curColor.r, m_curColor.g, m_curColor.b, m_curColor.a});

        this->m_vertices.push_back(bottomLeftX + size);
        this->m_vertices.push_back(bottomLeftY);
        this->m_vertices.push_back(1);
        this->m_vertices.push_back(1);

        this->m_vertices.insert(this->m_vertices.end(), {m_curColor.r, m_curColor.g, m_curColor.b, m_curColor.a});

        this->m_vertices.push_back(bottomLeftX + size / 2.0);
        this->m_vertices.push_back(bottomLeftY + size);
        this->m_vertices.push_back(1);
        this->m_vertices.push_back(1);
        
        this->m_vertices.insert(this->m_vertices.end(), {m_curColor.r, m_curColor.g, m_curColor.b, m_curColor.a});
        
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

    void OpenGLRenderer::SubmitCube(glm::vec3 position, float side_len){
        this->m_vertices.insert(m_vertices.end(), {position.x, position.y, position.z, 1.0, m_curColor.r, m_curColor.g, m_curColor.b, m_curColor.a});
        this->m_vertices.insert(m_vertices.end(), {position.x+side_len, position.y, position.z, 1.0, m_curColor.r, m_curColor.g, m_curColor.b, m_curColor.a});
        this->m_vertices.insert(m_vertices.end(), {position.x+side_len, position.y+side_len, position.z, 1.0, m_curColor.r, m_curColor.g, m_curColor.b, m_curColor.a});

        this->m_vertices.insert(m_vertices.end(), {position.x, position.y, position.z, 1.0, m_curColor.r, m_curColor.g, m_curColor.b, m_curColor.a});
        this->m_vertices.insert(m_vertices.end(), {position.x, position.y+side_len, position.z, 1.0, m_curColor.r, m_curColor.g, m_curColor.b, m_curColor.a});
        this->m_vertices.insert(m_vertices.end(), {position.x+side_len, position.y+side_len, position.z, 1.0, m_curColor.r, m_curColor.g, m_curColor.b, m_curColor.a});

        this->m_vertices.insert(m_vertices.end(), {position.x, position.y, position.z, 1.0, m_curColor.r, m_curColor.g, m_curColor.b, m_curColor.a});
        this->m_vertices.insert(m_vertices.end(), {position.x+side_len, position.y, position.z, 1.0, m_curColor.r, m_curColor.g, m_curColor.b, m_curColor.a});
        this->m_vertices.insert(m_vertices.end(), {position.x+side_len, position.y, position.z+side_len, 1.0, m_curColor.r, m_curColor.g, m_curColor.b, m_curColor.a});

        this->m_vertices.insert(m_vertices.end(), {position.x, position.y, position.z, 1.0, m_curColor.r, m_curColor.g, m_curColor.b, m_curColor.a});
        this->m_vertices.insert(m_vertices.end(), {position.x, position.y, position.z+side_len, 1.0, m_curColor.r, m_curColor.g, m_curColor.b, m_curColor.a});
        this->m_vertices.insert(m_vertices.end(), {position.x+side_len, position.y, position.z+side_len, 1.0, m_curColor.r, m_curColor.g, m_curColor.b, m_curColor.a});
        
    }


    OpenGLRenderer::~OpenGLRenderer(){}


}