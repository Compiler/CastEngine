#pragma once
#include <Cast/Core/Rendering/Shapes/Shape.h>

namespace Cast{

    class Cube : public Shape{

        private:
            glm::vec4 _center;
            float _sideLength;

        public:
            Cube(glm::vec3 center, float sideLen){
                this->_center = {center.x, center.y, center.z, 1.0f};
                this->_sideLength = sideLen;
                VertexTemplate t{_center, _center, _center};

                this->setColor({0, 1, 1, 1});
                float offset = _sideLength / 2.0f;
                //top plane
                this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0}, m_color, m_color});
                this->m_vertices.push_back({{_center.x + offset, _center.y, _center.z + offset, 1.0}, m_color, m_color});
                this->m_vertices.push_back({{_center.x, _center.y, _center.z + offset, 1.0}, m_color, m_color});
                this->m_vertices.push_back({{_center.x, _center.y, _center.z + offset, 1.0}, m_color, m_color});
                this->m_vertices.push_back({{_center.x, _center.y + offset, _center.z + offset, 1.0}, m_color, m_color});
                this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0}, m_color, m_color});

                this->setColor({0, 1, 0, 1});
                //bottom plane
                this->m_vertices.push_back({{_center.x, _center.y, _center.z, 1.0}, m_color, m_color});
                this->m_vertices.push_back({{_center.x + offset, _center.y, _center.z, 1.0}, m_color, m_color});
                this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z, 1.0}, m_color, m_color});
                this->m_vertices.push_back({{_center.x + offset, _center.y + offset, _center.z, 1.0}, m_color, m_color});
                this->m_vertices.push_back({{_center.x, _center.y + offset, _center.z, 1.0}, m_color, m_color});
                this->m_vertices.push_back({{_center.x, _center.y, _center.z, 1.0}, m_color, m_color});


                this->setColor({1, 0, 0, 1});
                //top plane
                this->m_vertices.push_back({{_center.x + offset, _center.y, _center.z + offset, 1.0}, m_color, m_color});
                this->m_vertices.push_back({{_center.x + offset, _center.y, _center.z, 1.0}, m_color, m_color});
                this->m_vertices.push_back({{_center.x, _center.y, _center.z, 1.0}, m_color, m_color});
                this->m_vertices.push_back({{_center.x, _center.y, _center.z, 1.0}, m_color, m_color});
                this->m_vertices.push_back({{_center.x, _center.y, _center.z + offset, 1.0}, m_color, m_color});
                this->m_vertices.push_back({{_center.x + offset, _center.y, _center.z + offset, 1.0}, m_color, m_color});

                //bottom plane


            }
            


    };


}