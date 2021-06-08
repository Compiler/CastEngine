#pragma once
#include <Cast/Core/Rendering/RenderContext.h>
#include <GLFW/glfw3.h>
namespace Cast{

    class OpenGLContext : public Cast::RenderContext{

        public:
            void clearColor(float r, float g, float b, float a);
            void clearDepthBit();
            void clearColorBit();

            

    };


}