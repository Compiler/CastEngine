#pragma once
#include <vector>
#include <Cast/Core/Rendering/Renderer.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
namespace Cast{


    class Shape{

        protected:
            std::vector<VertexTemplate> m_vertices{};
            glm::vec4 m_color{1.0f, 0.0f, 0.7f, 1.0f};

            glm::mat4 m_model{1};
            glm::mat4 m_translation{1};
            glm::mat4 m_rotation{1};
            glm::mat4 m_scale{1};

            bool m_dirty = true;

        public:
            virtual void Load() = 0;
            const inline std::vector<VertexTemplate>& getRendererVertices() const {return m_vertices;}
            void setColor(glm::vec4 color){this->m_color = color;}
            void Translate(glm::vec3 translation){this->m_translation = glm::translate(m_translation, translation);}
            void Rotate(float rotation, glm::vec3 axis){this->m_rotation = glm::rotate(this->m_rotation, rotation, axis);}
            inline const glm::mat4 GetModel()const{return m_translation * m_rotation * m_scale; }

    };

}