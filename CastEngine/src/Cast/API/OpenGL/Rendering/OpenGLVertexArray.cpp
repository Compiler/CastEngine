#include "OpenGLVertexArray.h"
namespace Cast{

    OpenGLVertexArray::OpenGLVertexArray(VAOLayout&& layout): _layout(std::move(layout)){
        glGenVertexArrays(1, &_id);  
        glBindVertexArray(_id);
        int count = 0;
        for(auto& item : _layout.elements){
            glEnableVertexAttribArray(count);
            glVertexAttribPointer(count++, item.count, GL_FLOAT, GL_FALSE, _layout.stride * sizeof(float), (void*)(item.offset * sizeof(float)));
            
        }
    }


}