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
            


    };


}