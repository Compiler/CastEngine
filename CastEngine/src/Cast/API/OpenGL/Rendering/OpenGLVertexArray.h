#pragma once
#include <Cast/Core/Debug/Logger.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
namespace Cast{
    
    /**
     * Helper container for VAOElements. Just serves as a unit that has a count.
     */
    struct VAOElement{
        int count;
        friend class VAOLayout;
        friend class OpenGLVertexArray;
        VAOElement(int count): count(count){}
        private:
            int _offset;

    };
    /**
     * Helper struct to hide setting implementation from user. They just setup a layout
     * The way they specify a layout is by only using one type(float) and specifying where they exist and how many of them there are
     */
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
            //TODO: Add a parameter named "Data layout" that allows for different orientations in memory
            /**
             *This orientation only allows for e0,e1,e2,...,en layouts It doesnt allow for swizzling in between 
            */
            void _calculate_settings(){
                int sum = 0;
                for(auto& element : elements){
                    element._offset = sum;
                    sum += element.count;
                }

                this->stride = sum;
            }
    };
    /**
     * Class for storing the layout and configuration of a VAO
     */
    class OpenGLVertexArray{
        private:
            unsigned int _id;
            VAOLayout _layout;

        public:
            OpenGLVertexArray() = default;
            OpenGLVertexArray(VAOLayout&& layout);
            void init(bool generateVAO = true);
            inline void setLayout(VAOLayout&& layout) noexcept {_layout = std::move(layout);}

    };

}