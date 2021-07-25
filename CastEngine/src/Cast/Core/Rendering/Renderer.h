#pragma once
#include <glm/vec3.hpp>
#include <Cast/Core/Rendering/RenderContext.h>

namespace Cast{

    class Renderer{

        public:
            virtual void DrawTriangle(glm::vec3 vertices[3]) = 0;
            static RenderContext::API GetAPI(){return RenderContext::GetAPI();}

    };

}