#pragma once
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
namespace Cast{

    class PerspectiveCamera{
        private:
            glm::vec3 _cameraPos;
            glm::vec3 _cameraTarget;
            glm::vec2 _cameraDimensions;
            glm::vec3 _cameraUp;
            glm::mat4 _projection, _view;
            bool _needsUpdate = true;
            bool _yDown;
            float _fov, _near, _far;
        public:
            PerspectiveCamera() = default;
            PerspectiveCamera(float camWidth, float camHeight, bool yDown = false);
            PerspectiveCamera(float camWidth, float camHeight, glm::vec3 camPos, bool yDown = false);
            void Update();


            inline const glm::mat4& getProjection(){return _projection;}
            inline const glm::mat4& getView(){return _view;}
            inline const glm::vec3& getPosition() const{return _cameraPos;}



    };

}