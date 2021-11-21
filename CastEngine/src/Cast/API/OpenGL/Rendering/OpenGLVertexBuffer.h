#pragma once
#include <memory>
#include <vector>
#include <Cast/Core/Debug/Logger.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace Cast{
    template<typename T>
    class OpenGLVertexBuffer{
        private:
            std::vector<T> _buffer;
            uint32_t _id;
        public:
            OpenGLVertexBuffer() = default;
            OpenGLVertexBuffer(std::vector<T>&& buffer) noexcept :_buffer(std::move(buffer)) {
                CAST_ASSERT(std::is_fundamental<T>());
            }

            void init(){
                glGenBuffers(1, &this->_id);  
                glBindBuffer(GL_ARRAY_BUFFER, this->_id);  
               
            }

            void buffer(uint32_t drawType = GL_STATIC_DRAW){
                glBindBuffer(GL_ARRAY_BUFFER, this->_id);  
                CAST_ASSERT(_buffer.size() > 0);
                glBufferData(GL_ARRAY_BUFFER, sizeof(_buffer[0]) * _buffer.size(), _buffer.data(), drawType);
            }

            void setVerticesBuffer(std::vector<T>& buffer){
                _buffer = buffer;
            }
            void setVertices(std::vector<T> buffer){
                _buffer = std::move(buffer);
            }

    };

}