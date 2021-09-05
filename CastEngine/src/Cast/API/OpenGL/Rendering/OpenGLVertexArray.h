#pragma once
#include <Cast/Core/Debug/Logger.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
namespace Cast{
    struct VAOElement{
        int count;
        friend class VAOLayout;
        friend class OpenGLVertexArray;
        VAOElement(int count): count(count){}
        private:
            int _offset;

    };
    struct VAOLayout{
        public:
            std::vector<VAOElement> elements;
            int stride;
            VAOLayout(){}
            VAOLayout(std::initializer_list<VAOElement> elements){
                this->elements = std::vector<VAOElement>(elements.begin(), elements.end());
                _calculate_settings();
            }

            void setElements(std::initializer_list<VAOElement> elements){
                this->elements = std::vector<VAOElement>(elements.begin(), elements.end());
                _calculate_settings();
            }


        private:
            void _calculate_settings(){
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
            OpenGLVertexArray() = default;
            OpenGLVertexArray(VAOLayout&& layout);
            void init();
            inline void setLayout(VAOLayout&& layout) noexcept {_layout = std::move(layout);}

    };

}