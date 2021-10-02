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
            virtual void clearColor(float r, float g, float b, float a) = 0;
            virtual void clearDepthBit() = 0;
            virtual void clearColorBit() = 0;
            virtual void SubmitTriangle(glm::vec3 vertices[3], glm::vec3 color[3]) = 0;
            virtual void SubmitTriangle(float bottomLeftX, float bottomLeftY, float size) = 0;
            virtual void Draw() = 0;
            virtual ~Renderer(){}

            static RenderContext::API GetAPI(){return RenderContext::GetAPI();}

    };

}