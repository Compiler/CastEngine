#pragma once
#include <Cast/Core/Rendering/RenderContext.h>

namespace Cast{

    class Renderer{

        public:
            static void Create();
            static void Destroy();
            static RenderContext::API getAPI(){return RenderContext::getAPI();}

    };

}