#pragma once


namespace Cast{
    /*
        RenderContext is an abstract class that allows for switching between different rendering contexts(opengl, vulkan, directx)
    */
    class RenderContext{
        
        public:
            enum class API{
                None = 0, OpenGL = 1, DirectX = 2, Vulkan = 3
            };

    };



}