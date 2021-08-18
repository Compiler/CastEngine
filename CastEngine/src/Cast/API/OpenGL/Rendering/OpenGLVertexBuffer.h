#pragma once
#include <memory>
namespace Cast{

    class OpenGLVertexBuffer{
        private:
            float* _buffer;
        public:
            VertexBuffer(float* buffer);

    };

}