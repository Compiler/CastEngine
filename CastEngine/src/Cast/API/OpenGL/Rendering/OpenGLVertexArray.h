#pragma once
#include <Cast/Core/Debug/Logger.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
namespace Cast{
    struct VAOElement{
        int count;
        friend class VAOLayout;
        VAOElement(int count): count(count){}
        private:
            int _offset;

    };
    struct VAOLayout{
        std::vector<VAOElement> elements;
        int stride;
        void calculate_settings(){
            int sum = 0;
            for(auto& element : elements){
                element._offset = sum;
                sum += element.count;
            }

            this->stride = sum;
        }
    };
    class OpenGLVertexArray{
        private:
            unsigned int _id;
            VAOLayout _layout;

        public:
            OpenGLVertexArray(VAOLayout&& layout);
            inline void setLayout(VAOLayout&& layout) noexcept {_layout = std::move(layout);}

    };

}