#include "OpenGLVertexArray.h"
namespace Cast{

    OpenGLVertexArray::OpenGLVertexArray(VAOLayout&& layout): _layout(std::move(layout)){
        glGenVertexArrays(1, &_id);  
        glBindVertexArray(_id);
        for(int i = 0; i < _layout.elements.size(); i++){
            const auto& item =_layout.elements[i];
            glVertexAttribPointer(i, item.count, GL_FLOAT, GL_FALSE, _layout.stride * sizeof(float), (void*)(item._offset * sizeof(float)));
            glEnableVertexAttribArray(i);
        }
    }


}