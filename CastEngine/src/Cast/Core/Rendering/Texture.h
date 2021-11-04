#pragma once
#include <stdint.h>

namespace Cast{

    class Texture{

        protected:
            
            uint32_t m_width, m_height;
            

        public:
            Texture();
            Texture(uint32_t width, uint32_t height);
            virtual void init(uint32_t width, uint32_t height);
        
    };

}