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
        m_model = GetModel();
        this->setColor({1,0,0,1});
        //front plane
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, m_model});

        this->setColor({1,0,1,1});
        //left plane
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, m_model});

        this->setColor({0, 1,0,1});

        //right plane
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, m_model});


        this->setColor({0, 0, 1,1});

        //top plane
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, m_model});


        this->setColor({0, 1, 1,1});
        //bottom plane
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, m_model});

        this->setColor({1, 1, 0,1});
        //back plane
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, m_model});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, m_model});

    }



}