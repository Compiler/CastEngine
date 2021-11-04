#include "Texture.h"

namespace Cast{

    Texture::Texture(): m_width(0), m_height(0){

    }

    Texture::Texture(uint32_t width, uint32_t height): m_width(width), m_height(height){
    }

    void Texture::init(uint32_t width, uint32_t height){
        this->m_width = width;
        this->m_height = height;
    }


}