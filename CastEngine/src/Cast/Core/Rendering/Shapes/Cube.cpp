#include "Cube.h"

namespace Cast{


    Cube::Cube(){
        this->_sideLength = 1.0f;
        Load();
    }

    Cube::Cube(glm::vec3 center, float sideLen): _sideLength(sideLen){
        this->Translate(center);
        Load();
    }

    Cube::Cube(glm::vec3 center, float sideLen, float rotation, glm::vec3 axis): _sideLength(sideLen){
        this->Translate(center);
        this->Rotate(rotation, axis);
        Load();

        
        
    }


    Cube::Cube(glm::vec4 color){
        this->_sideLength = 1.0f;
        this->m_color = color;
        Load();
    }

    Cube::Cube(glm::vec3 center, float sideLen, glm::vec4 color): _sideLength(sideLen){
        this->Translate(center);
        this->m_color = color;
        Load();
    }

    Cube::Cube(glm::vec3 center, float sideLen, float rotation, glm::vec3 axis, glm::vec4 color): _sideLength(sideLen){
        this->m_color = color;
        this->Rotate(rotation, axis);
        this->Translate(center);
        Load();
    }



    void Cube::Load(){
        float offset = _sideLength / 2.0f;
        this->m_vertices.clear();
        //glm::vec3 center = GetModel() * _center;
        auto model = GetModel();

        

        auto normal_model = model;//glm::mat4(1);
        //front plane
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(0, 0, 1.0f, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(0, 0, 1.0f, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(0, 0, 1.0f, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(0, 0, 1.0f, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(0, 0, 1.0f, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(0, 0, 1.0f, 1.0f)});

        //left plane
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(-1.0f, 0, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(-1.0f, 0, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(-1.0f, 0, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(-1.0f, 0, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(-1.0f, 0, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(-1.0f, 0, 0, 1.0f)});

        //right plane
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(1.0f, 0, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(1.0f, 0, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(1.0f, 0, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(1.0f, 0, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(1.0f, 0, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(1.0f, 0, 0, 1.0f)});

        //top plane
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(0, 1.0f, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(0, 1.0f, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(0, 1.0f, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(0, 1.0f, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(0, 1.0f, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(0, 1.0f, 0, 1.0f)});


        //bottom plane
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(0, -1.0f, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(0, -1.0f, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(0, -1.0f, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(0, -1.0f, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(0, -1.0f, 0, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z + offset, 1.0), m_color, normal_model * glm::vec4(0, -1.0f, 0, 1.0f)});

        //back plane
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(0, 0, -1.0f, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(0, 0, -1.0f, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(0, 0, -1.0f, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(0, 0, -1.0f, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(0, 0, -1.0f, 1.0f)});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, normal_model * glm::vec4(0, 0, -1.0f, 1.0f)});


    }



}