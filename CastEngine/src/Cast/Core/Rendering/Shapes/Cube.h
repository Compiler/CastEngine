#pragma once
#include <Cast/Core/Rendering/Shapes/Shape.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
namespace Cast{

    class Cube : public Shape{

        private:
            glm::vec4 _center{0, 0, 0, 1};
            float _sideLength;

        public:
            Cube();
            Cube(glm::vec3 center, float sideLen);
            Cube(glm::vec3 center, float sideLen, float rotation, glm::vec3 axis);

            Cube(glm::vec4 color);
            Cube(glm::vec3 center, float sideLen, glm::vec4 color);
            Cube(glm::vec3 center, float sideLen, float rotation, glm::vec3 axis, glm::vec4 color);
            
            void Load();


            inline static std::vector<VertexTemplate> GetIdentityCube(){
                std::vector<VertexTemplate> identity;
                float offset = 0.07125f;
                glm::mat4 identity_model = glm::mat4(1);
                glm::vec3 _center = {0, 0, 0};
                glm::vec4 m_color = {1,1,1,1};
                m_color = {1,0,0,1};
                //front plane
                identity.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, identity_model});
                identity.push_back({{_center.x + offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, identity_model});
                identity.push_back({{_center.x - offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, identity_model});
                identity.push_back({{_center.x - offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, identity_model});
                identity.push_back({{_center.x - offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, identity_model});
                identity.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 0, 1.0f, 1.0f}, identity_model});

                m_color = {1,0,1,1};
                //left plane
                identity.push_back({{_center.x - offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x - offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x - offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x - offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {-1.0f, 0, 0, 1.0f}, identity_model});

                m_color = {0, 1,0,1};

                //right plane
                identity.push_back({{_center.x + offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x + offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x + offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x + offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {1.0f, 0, 0, 1.0f}, identity_model});


                m_color = {0, 0, 1,1 };

                //top plane
                identity.push_back({{_center.x - offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x + offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x + offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x - offset, _center.y + offset, _center.z + offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x - offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 1.0f, 0, 1.0f}, identity_model});


                m_color = {0, 1, 1,1};
                //bottom plane
                identity.push_back({{_center.x + offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x + offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x - offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, identity_model});
                identity.push_back({{_center.x + offset, _center.y - offset, _center.z + offset, 1.0f}, m_color, {0, -1.0f, 0, 1.0f}, identity_model});

                m_color = {1, 1, 0,1};
                //back plane
                identity.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, identity_model});
                identity.push_back({{_center.x + offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, identity_model});
                identity.push_back({{_center.x + offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, identity_model});
                identity.push_back({{_center.x + offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, identity_model});
                identity.push_back({{_center.x - offset, _center.y + offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, identity_model});
                identity.push_back({{_center.x - offset, _center.y - offset, _center.z - offset, 1.0f}, m_color, {0, 0, -1.0f, 1.0f}, identity_model});

                return identity;
            }


            inline static std::vector<float> GetIdentityCubeFloats(){
                std::vector<VertexTemplate> verts = GetIdentityCube();
                std::vector<float> cube_floats;
                for(auto vertex : verts){
                    cube_floats.insert(cube_floats.end(), {vertex.position.x, vertex.position.y, vertex.position.z, vertex.position.w, 
                    vertex.color.x, vertex.color.y, vertex.color.z, vertex.color.w, vertex.normal.x, vertex.normal.y, vertex.normal.z, vertex.normal.w});
                }

                return cube_floats;
            }



    };


}