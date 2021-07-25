#pragma once
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Rendering/RenderContext.h>

namespace Cast{

    class Window{
        protected:
            int m_width, m_height;
            const char* m_windowName;
        public:
            Window(int width, int height, const char* windowName);
            virtual void update() = 0;
            virtual void render() = 0;
            virtual void destroy() = 0;
            virtual bool shouldClose() = 0;
            virtual void setSize(int width, int height) = 0;
            virtual void setPosition(int x, int y) = 0;


            inline int getHeight(){return m_height;}
            inline int getWidth(){return m_width;}



    };

}