#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/Director.hpp"
#include "Tower/Entity.hpp"
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    // class Camera
    // {
    // public:
    //     Camera(void);

    //     ~Camera(void);

    //     void Init(F32 fov = 45.0f, S32 width = 800, S32 height = 600, F32 near = 0.1f, F32 far = 100.0f);

    //     // TODO: Should delta time be part of this? Or should the camera just have its own clock? hmmm...
    //     // TODO: Should this live in the camera?
    //     //void KeyControl(const bool* keys, F64 deltaTime);

    //     // This is not the same as SET position
    //     void UpdatePosition(const glm::vec3& direction, F64 deltaTime);

    //     void SetPosition(const glm::vec3& position);

    //     void UpdateYawAndPitch(F32 yaw, F32 pitch);

    //     void CalculateViewMatrix(void);

    //     inline glm::mat4 GetProjectionMatrix(void) const { return _projection; }

    //     inline void SetViewMatrix(const glm::mat4& view) { _view = view; }

    //     inline const glm::mat4& GetViewMatrix(void) const { return _view; }

    //     inline void SetMovementSpeed(F32 speed) { _moveSpeed = speed; }

    //     void MoveForward(F32 delta);

    //     void MoveBack(F32 delta);

    //     void MoveRight(F32 delta);

    //     void MoveLeft(F32 delta);

    //     void Move(const glm::vec3& direction, F32 delta);

    //     // Update yaw by offset, apply turn speed
    //     void UpdateYaw(F32 offset);

    //     // Update pitch by offset, apply turn speed
    //     void UpdatePitch(F32 offset, bool clamp = true);

    //     inline void SetSensitivity(F32 sensitivity) { _sensitivity = sensitivity; }


    // private:
    //     void _UpdateVectors(void);

    //     shared_ptr<Entity> _target;
    //     glm::mat4 _view;
    //     glm::mat4 _projection;
    //     glm::vec3 _position;
    //     glm::vec3 _front;
    //     glm::vec3 _cameraUp;
    //     glm::vec3 _right;
    //     glm::vec3 _worldUp;
    //     F32 _yaw;
    //     F32 _pitch;
    //     F32 _moveSpeed;
    //     F32 _sensitivity;
    //     F32 _zoom;
    //     F32 _verticalOffset;
    //     F32 _targetOffset; // for a z forward world, this should be (0, 0, value)

    // };
    // typedef shared_ptr<Camera> p_Camera;
}