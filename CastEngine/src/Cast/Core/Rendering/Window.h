#pragma once
#include <Cast/Core/Debug/LoggingHeaderOnly.h>
#include <GLFW\glfw3.h>
#include <Cast/Core/Rendering/RenderContext.h>

namespace Cast{

    class Window{
        protected:
            int m_width; 
            int m_height;
            const char* m_windowName;
        public:
            Window(int width, int height, const char* windowName);
            virtual void update() = 0;
            virtual void destroy() = 0;
            virtual bool shouldClose() = 0;



    };

}