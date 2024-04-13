#include "pch.h"
#include "Tower/Components/Camera.hpp"

using namespace Tower;

Camera::Camera(void) :
    _target(nullptr),
    _view(1.0f),
    _projection(1.0f),
    _position(0.0f),
    _front(glm::vec3(0.0f, 0.0f, -1.0f)),
    _cameraUp(glm::vec3(0.0f, 1.0f, 0.0f)),
    _worldUp(glm::vec3(0.0f, 1.0f, 0.0)),
    _yaw(-90.0f),
    _pitch(0.0f),
    _moveSpeed(2.5f),
    _sensitivity(1.0f),
    _zoom(45.0f),
    _verticalOffset(1.0f),
    _targetOffset(1.0f)
{

}

Camera::~Camera(void)
{

}

void Camera::Init(F32 fov, S32 width, S32 height, F32 near, F32 far)
{
    // TODO: The first arg in the field of view. I like 90. This should be configurable
    _projection = glm::perspective(glm::radians(90.0f), (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
    CalculateViewMatrix();
}

void Camera::UpdatePosition(const glm::vec3& direction, F64 deltaTime)
{
    std::cout << "Camera::UpdatePosition called\n";
    glm::vec3 directionNormalized = glm::normalize(direction);
    real speed = _moveSpeed * F32(deltaTime);

    std::cout << "Speed = " << _moveSpeed << std::endl;

    _position -= directionNormalized * speed;
}

void Camera::SetPosition(const glm::vec3& position)
{
    _position = position;
    CalculateViewMatrix();
}


void Camera::UpdateYawAndPitch(F32 yaw, F32 pitch)
{
    // TODO:: Consider having two sensitivities, like, vertical and horizontal
    _yaw += yaw * _sensitivity;
    _pitch += pitch * _sensitivity;

    // Clamp less than 90 degrees
    if (_pitch > 89.0f)
    {
        _pitch = 89.0f;
    }

    if (_pitch < -89.0f)
    {
        _pitch = -89.0f;
    }
}


void Camera::CalculateViewMatrix(void)
{
    _UpdateVectors();
    _view = glm::lookAt(_position, _position + _front, _cameraUp);
}


void Camera::MoveForward(F32 delta)
{
    F32 velocity = _moveSpeed * delta;
    _position += _front * velocity;
}

void Camera::MoveBack(F32 delta)
{
    F32 velocity = _moveSpeed * delta;
    _position -= _front * velocity;
}

void Camera::MoveRight(F32 delta)
{
    F32 velocity = _moveSpeed * delta;
    _position += _right * velocity;
}

void Camera::MoveLeft(F32 delta)
{
    F32 velocity = _moveSpeed * delta;
    _position -= _right * velocity;
}

void Camera::Move(const glm::vec3& direction, F32 delta)
{
    _position += direction * (_moveSpeed * delta);
}


void Camera::UpdateYaw(F32 offset)
{
    _yaw += offset * _sensitivity;
}

void Camera::UpdatePitch(F32 offset, bool clamp)
{
    _pitch += offset * _sensitivity;

    if (clamp)
    {
        if (_pitch > 89.0f)
        {
            _pitch = 89.0f;
        }
        if (_pitch < -89.0f)
        {
            _pitch = 89.0f;
        }
    }
}

void Camera::_UpdateVectors(void)
{
    _front.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
    _front.y = sin(glm::radians(_pitch));
    _front.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));
    _front = glm::normalize(_front);

    _right = glm::normalize(glm::cross(_front, _worldUp));
    _cameraUp = glm::normalize(glm::cross(_right, _front));

    _position = _target->GetPosition() + _targetOffset;
}