#pragma once

#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Rendering/RenderContext.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace Cast{

    class Window{
        protected:
            const char* m_windowName;
            GLFWwindow* m_window;
        public:
            static int WINDOW_WIDTH;
            static int WINDOW_HEIGHT;

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
                WINDOW_WIDTH = width;
                WINDOW_HEIGHT = height;
                glfwSetWindowSize(m_window, WINDOW_WIDTH, WINDOW_HEIGHT);
            }

            void setPosition(int x, int y){
                glfwSetWindowPos(m_window, x, y);
            }


            inline GLFWwindow* getWindowHandle(){return m_window;}
            inline bool shouldClose(){return glfwWindowShouldClose(m_window);}
            inline void setShouldClose(){glfwSetWindowShouldClose(m_window, GLFW_TRUE);}
            inline void hideWindow()const{glfwHideWindow(m_window);}
            inline void showWindow()const{glfwShowWindow(m_window);}
            inline void focusWindow()const{glfwFocusWindow(m_window);}



    };

}