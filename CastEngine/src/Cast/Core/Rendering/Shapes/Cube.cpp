#include "Cube.h"

namespace Cast{


    Cube::Cube(){
        this->_center = {0, 0, 0, 1};
        this->_sideLength = 1.0f;
        load();
    }

    Cube::Cube(glm::vec3 center, float sideLen): _sideLength(sideLen){
        this->_center = {center.x, center.y, center.z, 1.0f};
        load();
    }

    Cube::Cube(glm::vec3 center, float sideLen, float rotation, glm::vec3 axis): _sideLength(sideLen){
        this->_center = {center.x, center.y, center.z, 1.0f};
        load(rotation, axis);
    }


    Cube::Cube(glm::vec4 color){
        this->_center = {0, 0, 0, 1};
        this->_sideLength = 1.0f;
        this->m_color = color;
        load();
    }

    Cube::Cube(glm::vec3 center, float sideLen, glm::vec4 color): _sideLength(sideLen){
        this->_center = {center.x, center.y, center.z, 1.0f};
        this->m_color = color;
        load();
    }

    Cube::Cube(glm::vec3 center, float sideLen, float rotation, glm::vec3 axis, glm::vec4 color): _sideLength(sideLen){
        this->_center = {center.x, center.y, center.z, 1.0f};
        this->m_color = color;
        load(rotation, axis);
    }



    void Cube::load(){
        float offset = _sideLength / 2.0f;

        //front plane
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z + offset, 1.0}, m_color, {0, 0, 1.0f, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z + offset, 1.0}, m_color, {0, 0, 1.0f, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0}, m_color, {0, 0, 1.0f, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0}, m_color, {0, 0, 1.0f, 1.0f}});
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z + offset, 1.0}, m_color, {0, 0, 1.0f, 1.0f}});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z + offset, 1.0}, m_color, {0, 0, 1.0f, 1.0f}});

        //left plane
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z + offset, 1.0}, m_color, {-1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z + offset, 1.0}, m_color, {-1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0}, m_color, {-1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0}, m_color, {-1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z - offset, 1.0}, m_color, {-1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z + offset, 1.0}, m_color, {-1.0f, 0, 0, 1.0f}});

        //right plane
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z - offset, 1.0}, m_color, {1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z + offset, 1.0}, m_color, {1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0}, m_color, {1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0}, m_color, {1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z - offset, 1.0}, m_color, {1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z - offset, 1.0}, m_color, {1.0f, 0, 0, 1.0f}});



        //top plane
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z - offset, 1.0}, m_color, {0, 1.0f, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z - offset, 1.0}, m_color, {0, 1.0f, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0}, m_color, {0, 1.0f, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0}, m_color, {0, 1.0f, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z + offset, 1.0}, m_color, {0, 1.0f, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z - offset, 1.0}, m_color, {0, 1.0f, 0, 1.0f}});


        //bottom plane
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z + offset, 1.0}, m_color, {0, -1.0f, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z - offset, 1.0}, m_color, {0, -1.0f, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0}, m_color, {0, -1.0f, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0}, m_color, {0, -1.0f, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z + offset, 1.0}, m_color, {0, -1.0f, 0, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z + offset, 1.0}, m_color, {0, -1.0f, 0, 1.0f}});

        //back plane
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0}, m_color, {0, 0, -1.0f, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y - offset, _center.z - offset, 1.0}, m_color, {0, 0, -1.0f, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z - offset, 1.0}, m_color, {0, 0, -1.0f, 1.0f}});
        this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z - offset, 1.0}, m_color, {0, 0, -1.0f, 1.0f}});
        this->m_vertices.push_back({{_center.x - offset, _center.y + offset, _center.z - offset, 1.0}, m_color, {0, 0, -1.0f, 1.0f}});
        this->m_vertices.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0}, m_color, {0, 0, -1.0f, 1.0f}});


    }






    void Cube::load(float rotation, glm::vec3 axis){
        glm::mat4 rot{1};
        rot = glm::rotate(rot, rotation, axis);
        
        glm::vec3 center = rot * _center;
        this->_center = {center.x, center.y, center.z, 1.0f};

        float offset = _sideLength / 2.0f;


        //TODO: literally like 1/20th of the computation needs to be done to make this work, just store the normal rot in a var and pass it.

        //front plane
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y - offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{0, 0, 1.0f, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y - offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{0, 0, 1.0f, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y + offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{0, 0, 1.0f, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y + offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{0, 0, 1.0f, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y + offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{0, 0, 1.0f, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y - offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{0, 0, 1.0f, 1.0f}});

        //left plane
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y + offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{-1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y - offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{-1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y - offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{-1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y - offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{-1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y + offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{-1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y + offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{-1.0f, 0, 0, 1.0f}});

        //right plane
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y - offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y - offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y + offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y + offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y + offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y - offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{1.0f, 0, 0, 1.0f}});



        //top plane
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y + offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{0, 1.0f, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y + offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{0, 1.0f, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y + offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{0, 1.0f, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y + offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{0, 1.0f, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y + offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{0, 1.0f, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y + offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{0, 1.0f, 0, 1.0f}});


        //bottom plane
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y - offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{0, -1.0f, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y - offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{0, -1.0f, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y - offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{0, -1.0f, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y - offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{0, -1.0f, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y - offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{0, -1.0f, 0, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y - offset, _center.z + offset, 1.0}, m_color, rot * glm::vec4{0, -1.0f, 0, 1.0f}});

        //back plane
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y - offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{0, 0, -1.0f, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y - offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{0, 0, -1.0f, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y + offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{0, 0, -1.0f, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x + offset, _center.y + offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{0, 0, -1.0f, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y + offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{0, 0, -1.0f, 1.0f}});
        this->m_vertices.push_back({rot * glm::vec4{_center.x - offset, _center.y - offset, _center.z - offset, 1.0}, m_color, rot * glm::vec4{0, 0, -1.0f, 1.0f}});


    }
}