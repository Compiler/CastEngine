#pragma once
#include <Cast/Core/Rendering/RenderContext.h>

namespace Cast{

    class VulkanContext : public Cast::RenderContext{

        public:
            VulkanContext();
            void clearColor(float r, float g, float b, float a);
            void clearDepthBit();
            void clearColorBit();

            

    };


}