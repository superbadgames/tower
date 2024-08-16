#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/Director.hpp"
#include "Tower/Entity.hpp"
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    class Camera2D
    {
    public:
        Camera2D(void);

        ~Camera2D(void);

        void Init(F32 screenWidth = 1200.0f, F32 screenHeight = 800.0f);

        void SetPosition(const glm::vec2& position);

        void CalculateViewMatrix(void);

        inline const glm::mat4& GetViewMatrix(void) const { return _view; }


    private:
        glm::vec3 _target;
        glm::mat4 _view;
        glm::mat4 _projection;
        glm::vec3 _position;
        glm::vec3 _front;
        glm::vec3 _cameraUp;
        glm::vec3 _right;

    };
    typedef shared_ptr<Camera2D> p_Camera2D;
}