#pragma once
#include <memory>
namespace Cast{

    class VertexBuffer{
        private:
            float* _buffer;
        public:
            VertexBuffer(float* buffer);

    };

}