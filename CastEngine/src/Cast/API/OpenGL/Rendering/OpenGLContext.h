#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Cast/Core/Rendering/RenderContext.h>
#include <Cast/API/OpenGL/OpenGLWindow.h>

namespace Cast{

    class OpenGLContext : public Cast::RenderContext{

        public:
            OpenGLContext();
            

            
            void Load();
            void Update();
            void Render();
            void Unload();
            

    };


}