#pragma once
#include <vector>
#include <Cast/Core/Rendering/Renderer.h>
namespace Cast{


    class Shape{

        protected:
            std::vector<VertexTemplate> m_vertices{};
            glm::vec4 m_color{1.0f, 0.0f, 0.7f, 1.0f};


        public:
            const inline std::vector<VertexTemplate>& getRendererVertices() const {return m_vertices;}
            void setColor(glm::vec4 color){this->m_color = color;}

    };

}