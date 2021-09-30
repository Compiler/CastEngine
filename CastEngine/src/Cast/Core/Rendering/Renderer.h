#pragma once
#include <glm/vec3.hpp>
#include <vector>
#include <Cast/Core/Rendering/RenderContext.h>

namespace Cast{

    class Renderer{
        protected:
            std::vector<float> m_vertices;
            int m_currentAliveVertices;
            int m_offsetToAliveVertices;
        public:
            static int MAX_VERTICES;
            Renderer():m_currentAliveVertices(0),m_offsetToAliveVertices(0){}
            virtual void SubmitTriangle(glm::vec3 vertices[3], glm::vec3 color[3]) = 0;
            virtual void SubmitTriangle(float centerX, float centerY, float size, float orientation]) = 0;
            virtual void Draw() = 0;
            virtual ~Renderer(){}

            static RenderContext::API GetAPI(){return RenderContext::GetAPI();}

    };

}