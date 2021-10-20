#include "Texture.h"

namespace Cast{

    Texture::Texture(): _width(0), _height(0){

    }

    Texture::Texture(uint32_t width, uint32_t height){
        this->_width = width;
        this->_height = height;
    }

    void Texture::init(uint32_t width, uint32_t height){
        this->_width = width;
        this->_height = height;
    }


}