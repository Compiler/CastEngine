#include "PerspectiveCamera.h"


namespace Cast{


    PerspectiveCamera::PerspectiveCamera(float camWidth, float camHeight, bool yDown): _near(0.1f), _far(100.0f), _fov(90), _yDown(yDown){
        _cameraDimensions = {camWidth, camHeight};
        _cameraUp = _yDown ? glm::vec3{0.0f, -1.0f, 0.0f} : glm::vec3{0.0f, 1.0f, 0.0f};
        _cameraTarget = {0.0f, 0.0f, 0.0f};
        _cameraPos = {0.0f, 0.0f, 1.0f};
        Update();
    }

    PerspectiveCamera::PerspectiveCamera(float camWidth, float camHeight, glm::vec3 camPos, bool yDown): _near(0.1f), _far(100.0f), _cameraPos(camPos), _fov(90), _yDown(yDown){
        _cameraDimensions = {camWidth, camHeight};
        _cameraUp = _yDown ? glm::vec3{0.0f, -1.0f, 0.0f} : glm::vec3{0.0f, 1.0f, 0.0f};
        _cameraTarget = {0.0f, 0.0f, 0.0f};
        Update();
    }

    void PerspectiveCamera::Update(){
        if(_needsUpdate){
            _projection = glm::perspective(glm::radians(_fov), _cameraDimensions.x / _cameraDimensions.y, _near, _far);
            _projection[1][1] *= -1;
            if(_yDown){
                _projection[0][0] *= -1;
            }
            _view = glm::lookAt(_cameraPos, _cameraTarget, _cameraUp);
        }


        _needsUpdate = false;
    }

}