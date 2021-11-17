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
        this->Translate(center);
        this->m_color = color;
        this->Rotate(rotation, axis);
        //TODO: THIS IS TESTING CODE< DELETE!
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::rotate(trans, glm::radians(rotation), axis);
        trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));  

        glm::mat4 model{1};
        glm::mat4 tran{1};
        glm::mat4 rot{1};
        glm::mat4 scale{1};

        rot = glm::rotate(trans, glm::radians(rotation), axis);
        scale = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));  

        model = rot * scale;

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                CAST_ERROR("{} = {}", trans[i][j], model[i][j]);
            }
        }
        Load();
    }



    void Cube::Load(){
        float offset = _sideLength / 2.0f;

        //glm::vec3 center = GetModel() * _center;
        auto model = GetModel();
        //front plane
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z + offset, 1.0), m_color, {0, 0, 1.0f, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z + offset, 1.0), m_color, {0, 0, 1.0f, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, {0, 0, 1.0f, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, {0, 0, 1.0f, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z + offset, 1.0), m_color, {0, 0, 1.0f, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z + offset, 1.0), m_color, {0, 0, 1.0f, 1.0f}});

        //left plane
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z + offset, 1.0), m_color, {-1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z + offset, 1.0), m_color, {-1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, {-1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, {-1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z - offset, 1.0), m_color, {-1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z + offset, 1.0), m_color, {-1.0f, 0, 0, 1.0f}});

        //right plane
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z - offset, 1.0), m_color, {1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z + offset, 1.0), m_color, {1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, {1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, {1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z - offset, 1.0), m_color, {1.0f, 0, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z - offset, 1.0), m_color, {1.0f, 0, 0, 1.0f}});



        //top plane
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z - offset, 1.0), m_color, {0, 1.0f, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z - offset, 1.0), m_color, {0, 1.0f, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, {0, 1.0f, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, {0, 1.0f, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z + offset, 1.0), m_color, {0, 1.0f, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z - offset, 1.0), m_color, {0, 1.0f, 0, 1.0f}});


        //bottom plane
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z + offset, 1.0), m_color, {0, -1.0f, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z - offset, 1.0), m_color, {0, -1.0f, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, {0, -1.0f, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, {0, -1.0f, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z + offset, 1.0), m_color, {0, -1.0f, 0, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z + offset, 1.0), m_color, {0, -1.0f, 0, 1.0f}});

        //back plane
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, {0, 0, -1.0f, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y - offset, _center.z - offset, 1.0), m_color, {0, 0, -1.0f, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z - offset, 1.0), m_color, {0, 0, -1.0f, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x + offset, _center.y + offset, _center.z - offset, 1.0), m_color, {0, 0, -1.0f, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y + offset, _center.z - offset, 1.0), m_color, {0, 0, -1.0f, 1.0f}});
        this->m_vertices.push_back({model * glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, {0, 0, -1.0f, 1.0f}});


    }






    // void Cube::load(float rotation, glm::vec3 axis){
    //     glm::mat4 rot{1};
    //     rot = glm::rotate(rot, rotation, axis);
        
    //     glm::vec3 center = m_translation * _center;
    //     this->_center = {center.x, center.y, center.z, 1.0f};

    //     float offset = _sideLength / 2.0f;


    //     //TODO: literally like 1/20th of the computation needs to be done to make this work, just store the normal rot in a var and pass it.

    //     //front plane
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y - offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{0, 0, 1.0f, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y - offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{0, 0, 1.0f, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{0, 0, 1.0f, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{0, 0, 1.0f, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y + offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{0, 0, 1.0f, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y - offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{0, 0, 1.0f, 1.0f}});

    //     //left plane
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y + offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{-1.0f, 0, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y - offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{-1.0f, 0, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{-1.0f, 0, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{-1.0f, 0, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y + offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{-1.0f, 0, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y + offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{-1.0f, 0, 0, 1.0f}});

    //     //right plane
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y - offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{1.0f, 0, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y - offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{1.0f, 0, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{1.0f, 0, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{1.0f, 0, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y + offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{1.0f, 0, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y - offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{1.0f, 0, 0, 1.0f}});



    //     //top plane
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y + offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{0, 1.0f, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y + offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{0, 1.0f, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{0, 1.0f, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y + offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{0, 1.0f, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y + offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{0, 1.0f, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y + offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{0, 1.0f, 0, 1.0f}});


    //     //bottom plane
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y - offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{0, -1.0f, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y - offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{0, -1.0f, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{0, -1.0f, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{0, -1.0f, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y - offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{0, -1.0f, 0, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y - offset, _center.z + offset, 1.0), m_color, rot * glm::vec4{0, -1.0f, 0, 1.0f}});

    //     //back plane
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{0, 0, -1.0f, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y - offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{0, 0, -1.0f, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y + offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{0, 0, -1.0f, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x + offset, _center.y + offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{0, 0, -1.0f, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y + offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{0, 0, -1.0f, 1.0f}});
    //     this->m_vertices.push_back({rot * glm::vec4glm::vec4(_center.x - offset, _center.y - offset, _center.z - offset, 1.0), m_color, rot * glm::vec4{0, 0, -1.0f, 1.0f}});


    // }
}