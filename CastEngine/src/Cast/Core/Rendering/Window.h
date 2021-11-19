#pragma once

#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Rendering/RenderContext.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace Cast{

    class Window{
        protected:
            int m_width, m_height;
            const char* m_windowName;
            GLFWwindow* m_window;
        public:
            Window(int width, int height, const char* windowName);

            void update(){
                glfwPollEvents();    
            }
            void render(){
                glfwSwapBuffers(m_window);
            }
            void destroy(){
                CAST_WARN("Destroying VulkanWindow");
                glfwTerminate();
            }

            void setSize(int width, int height){
                m_width = width;
                m_height = height;
                glfwSetWindowSize(m_window, m_width, m_height);
            }

            void setPosition(int x, int y){
                glfwSetWindowPos(m_window, x, y);
            }


            inline GLFWwindow* getWindowHandle(){return m_window;}
            inline int getHeight(){return m_height;}
            inline int getWidth(){return m_width;}
            inline bool shouldClose(){return glfwWindowShouldClose(m_window);}
            inline void hideWindow()const{glfwHideWindow(m_window);}
            inline void showWindow()const{glfwShowWindow(m_window);}
            inline void focusWindow()const{glfwFocusWindow(m_window);}



    };

}