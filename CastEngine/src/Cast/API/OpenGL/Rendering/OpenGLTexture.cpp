#include "OpenGLTexture.h"

namespace Cast{

    OpenGLTexture::OpenGLTexture(){

    }

    OpenGLTexture::OpenGLTexture(uint32_t width, uint32_t height): Texture(width, height){
    }

    void OpenGLTexture::init(uint32_t width, uint32_t height){
        Texture::init(width, height);
        
    }


}