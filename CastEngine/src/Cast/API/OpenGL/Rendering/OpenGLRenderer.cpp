#include "OpenGLRenderer.h"

namespace Cast{

    OpenGLRenderer::OpenGLRenderer():Renderer(), _layout({VAOElement(4), VAOElement(4)}){ 
    }
    void OpenGLRenderer::SubmitTriangle(glm::vec3 vertices[3], glm::vec3 color[3]){
        CAST_DEBUG("OPENGL Drawing vertices!");
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


    void OpenGLRenderer::Draw(){
        _buffer.setVertices(std::move(m_vertices));
        _buffer.init();
        _vao.setLayout(std::move(_layout));
        _vao.init();
        glDrawArrays(GL_TRIANGLES, 0, 100);

        m_vertices.clear();
        
    }
     

}