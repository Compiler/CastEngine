#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Cast/Core/Rendering/RenderContext.h>
#include <Cast/Platform/OpenGL/OpenGLWindow.h>

namespace Cast{

    class OpenGLContext : public Cast::RenderContext{

        public:
            OpenGLContext();
            void clearColor(float r, float g, float b, float a);
            void clearDepthBit();
            void clearColorBit();

            

    };


}