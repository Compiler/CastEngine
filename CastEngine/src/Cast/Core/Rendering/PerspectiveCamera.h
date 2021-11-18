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
            bool _needsUpdate;
            bool _yUp;
            float _fov, _near, _far;
        public:

            PerspectiveCamera(float camWidth, float camHeight);
            void Update();



    };

}