#pragma once
#include <Cast/Core/Rendering/Window.h>

namespace Cast{
    class Window;
    /*
        RenderContext is an abstract class that allows for switching between different rendering contexts(opengl, vulkan, directx)
    */
    class RenderContext{

        protected:
            Cast::Window* m_window;
        
        public:
            enum class API{
                None = 0, OpenGL = 1, DirectX = 2, Vulkan = 3
            };
            enum class ClearBit{
                None = 0, Color = 1, Depth = 2, Stencil = 3 
            };

            void setAPI(API newAPI);
            static API getAPI();

            virtual void clearColor(float r, float g, float b, float a) = 0;
            virtual void clearDepthBit() = 0;
            virtual void clearColorBit() = 0;

            inline Window* getWindow(){return m_window;}

        private:
            static API _contextAPI;




    };



}