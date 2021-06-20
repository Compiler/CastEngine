#include "RenderContext.h"

Cast::RenderContext::API Cast::RenderContext::_contextAPI = Cast::RenderContext::API::OpenGL; //default to OpenGL context 

namespace Cast{

    void RenderContext::setAPI(RenderContext::API newAPI){
        this->_contextAPI = newAPI;
    }
    RenderContext::API RenderContext::GetAPI(){return _contextAPI;}

}