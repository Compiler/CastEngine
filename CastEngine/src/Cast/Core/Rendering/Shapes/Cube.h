#pragma once
#include <Cast/Core/Rendering/Shapes/Shape.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
namespace Cast{

    class Cube : public Shape{

        private:
            glm::vec4 _center;
            float _sideLength;

        public:
            Cube(glm::vec3 center, float sideLen){
                this->_center = {center.x, center.y, center.z, 1.0f};
                this->_sideLength = sideLen;

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

            Cube(glm::vec3 center, float sideLen, float rotation, glm::vec3 axis){
                glm::mat4 rot{1};
                rot = glm::rotate(rot, rotation, axis);

                CAST_ERROR("{}, {}, {} ", center.x, center.y, center.z);
                center = rot * glm::vec4(center, 1.0);
                this->_center = {center.x, center.y, center.z, 1.0f};
                this->_sideLength = sideLen;
                CAST_ERROR("{}, {}, {} ", center.x, center.y, center.z);

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
            


    };


}