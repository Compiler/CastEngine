#include "Window.h"

namespace Cast{

    int Window::WINDOW_WIDTH = 1920;
    int Window::WINDOW_HEIGHT= 1080;
    Window::Window(int width, int height, const char* windowName): m_windowName(windowName){
        WINDOW_WIDTH = width;
        WINDOW_HEIGHT = height;
    }




}