#include "Cube.h"

namespace Cast{


    Cube::Cube(){
        this->m_vertices.resize(NUM_VERTICES);
        this->_sideLength = 1.0f;
        Load();
    }

    Cube::Cube(glm::vec3 center, float sideLen): _sideLength(sideLen){
        this->m_vertices.resize(NUM_VERTICES);
        this->Translate(center);
        Load();
    }

    Cube::Cube(glm::vec3 center, float sideLen, float rotation, glm::vec3 axis): _sideLength(sideLen){
        this->m_vertices.resize(NUM_VERTICES);
        this->Translate(center);
        this->Rotate(rotation, axis);
        Load();

    }


    Cube::Cube(glm::vec4 color){
        this->m_vertices.resize(NUM_VERTICES);
        this->_sideLength = 1.0f;
        this->m_color = color;
        Load();
    }

    Cube::Cube(glm::vec3 center, float sideLen, float rotation, glm::vec3 axis, glm::vec4 color): _sideLength(sideLen){
        this->m_vertices.resize(NUM_VERTICES);
        this->m_color = color;
        this->Rotate(rotation, axis);
        this->Translate(center);
        Load();
    }

    

    Cube::Cube(glm::vec3 center, float sideLen, glm::vec4 color): _sideLength(sideLen){
        this->m_vertices.resize(NUM_VERTICES);
        this->m_color = color;
        this->Translate(center);
        Load();
    }
    Cube::Cube(glm::vec4 center, float sideLen, glm::vec4 color): _sideLength(sideLen){
        this->m_vertices.resize(NUM_VERTICES);
        this->m_color = color;
        this->Translate(center);
        Load();
    }

    Cube::Cube(glm::vec4 center, float sideLen, glm::vec4 rotation, glm::vec4 scale, glm::vec4 color): _sideLength(sideLen){
        this->m_vertices.resize(NUM_VERTICES);
        this->m_color = color;
        this->Rotate(rotation);
        this->Scale(scale);
        this->Translate(center);
        Load();
    }
    
    Cube::Cube(glm::vec3 center, float sideLen, glm::vec4 rotation, glm::vec4 color): _sideLength(sideLen){
        this->m_vertices.resize(NUM_VERTICES);
        this->m_color = color;
        this->Rotate(rotation);
        this->Translate(center);
        Load();
    }
    

    void Cube::Load(){
        float offset = _sideLength / 2.0f;
        m_model = GetModel();
        //this->setColor({1,0,0,1});
        //front plane
        this->m_vertices[0] = {{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, m_model};
        this->m_vertices[1] = {{_center.x + offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, m_model};
        this->m_vertices[2] = {{_center.x - offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, m_model};
        this->m_vertices[3] = {{_center.x - offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, m_model};
        this->m_vertices[4] = {{_center.x - offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, m_model};
        this->m_vertices[5] = {{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, m_model};

        //this->setColor({1,0,1,1});
        //left plane
        this->m_vertices[6] = {{_center.x - offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, m_model};
        this->m_vertices[7] = {{_center.x - offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, m_model};
        this->m_vertices[8] = {{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, m_model};
        this->m_vertices[9] = {{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, m_model};
        this->m_vertices[10] = {{_center.x - offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, m_model};
        this->m_vertices[11] = {{_center.x - offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, m_model};

        //this->setColor({0, 1,0,1});

        //right plane
        this->m_vertices[12] = {{_center.x + offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, m_model};
        this->m_vertices[13] = {{_center.x + offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, m_model};
        this->m_vertices[14] = {{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, m_model};
        this->m_vertices[15] = {{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, m_model};
        this->m_vertices[16] = {{_center.x + offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, m_model};
        this->m_vertices[17] = {{_center.x + offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, m_model};


        //this->setColor({0, 0, 1,1});

        //top plane
        this->m_vertices[18] = {{_center.x - offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, m_model};
        this->m_vertices[19] = {{_center.x + offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, m_model};
        this->m_vertices[20] = {{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, m_model};
        this->m_vertices[21] = {{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, m_model};
        this->m_vertices[22] = {{_center.x - offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, m_model};
        this->m_vertices[23] = {{_center.x - offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, m_model};


        //this->setColor({0, 1, 1,1});
        //bottom plane
        this->m_vertices[24] = {{_center.x + offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, m_model};
        this->m_vertices[25] = {{_center.x + offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, m_model};
        this->m_vertices[26] = {{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, m_model};
        this->m_vertices[27] = {{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, m_model};
        this->m_vertices[28] = {{_center.x - offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, m_model};
        this->m_vertices[29] = {{_center.x + offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, m_model};

        //this->setColor({1, 1, 0,1});
        //back plane
        this->m_vertices[30] = {{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, m_model};
        this->m_vertices[31] = {{_center.x + offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, m_model};
        this->m_vertices[32] = {{_center.x + offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, m_model};
        this->m_vertices[33] = {{_center.x + offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, m_model};
        this->m_vertices[34] = {{_center.x - offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, m_model};
        this->m_vertices[35] = {{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, m_model};

    }



}