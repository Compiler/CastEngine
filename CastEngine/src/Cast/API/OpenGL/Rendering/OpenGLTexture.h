#pragma once

#include <Cast/Core/Rendering/Texture.h>

namespace Cast{

    class OpenGLTexture : public Texture{

        public:
            OpenGLTexture();
            OpenGLTexture(uint32_t width, uint32_t height);
            void init (uint32_t width, uint32_t height);



    };

}
