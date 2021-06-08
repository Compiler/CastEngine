#include "OpenGLContext.h"

namespace Cast{

    void OpenGLContext::clearColor(float r, float g, float b, float a){
        glClearColor(r,g,b,a);
    }
    void OpenGLContext::clearColorBit(){
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void OpenGLContext::clearDepthBit(){
        glClear(GL_DEPTH_BUFFER_BIT);
    }


}