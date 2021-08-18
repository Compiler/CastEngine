#pragma once
#include <Cast/Core/Rendering/Renderer.h>
namespace Cast{

    class OpenGLRenderer : public Renderer{
        public:
            void DrawTriangle(glm::vec3 vertices[3]);


    };

}