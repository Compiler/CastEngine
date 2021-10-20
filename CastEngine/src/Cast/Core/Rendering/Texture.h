#pragma once
#include <stdint.h>

namespace Cast{

    class Texture{

        private:
            
            uint32_t _width, _height;
            

        public:
            Texture();
            Texture(uint32_t width, uint32_t height);
            virtual void init(uint32_t width, uint32_t height);
        
    };

}