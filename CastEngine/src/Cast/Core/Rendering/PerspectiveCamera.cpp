#include "PerspectiveCamera.h"


namespace Cast{


    PerspectiveCamera::PerspectiveCamera(float camWidth, float camHeight): _near(0.1f), _far(10.0f){
        _cameraDimensions = {camWidth, camHeight};
        _cameraUp = {0.0f, -1.0f, 0.0f};
    }

    void PerspectiveCamera::Update(){
        if(_needsUpdate){
            _projection = glm::perspective(glm::radians(_fov), _cameraDimensions.x / _cameraDimensions.y, _near, _far);
            if(_yUp){
                _cameraUp = {0.0f, 1.0f, 0.0f};
                _projection[1][1] *= -1;
            }
            _cameraPos = {0.0f, 0.0f, 1.0f};
            _cameraTarget = {0.0f, 0.0f, 0.0f};
            _view = glm::lookAt(_cameraPos, _cameraTarget, _cameraUp);
        }
    }

}