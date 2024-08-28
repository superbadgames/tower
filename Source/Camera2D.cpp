#include "pch.h"
#include "Tower/Cameras/Camera2D.hpp"

using namespace Tower;

Camera2D::Camera2D(void) : _view(1.0f),
                           _projection(1.0f),
                           _position(glm::vec3(0.0f, 0.0f, 0.0f))
{
}

Camera2D::~Camera2D(void)
{
}

void Camera2D::Init(F32 screenWidth, F32 screenHeight)
{
    // Left, Right, Bottom, Top, Near, Far of the screen
    // I've hard coded left, bottom, near and far. For all 2D games, these should never change.
    // If I ever need to change them, I can easily do that here.
    _projection = glm::ortho(-screenWidth, screenWidth, -screenHeight, screenHeight, -0.1f, 100.0f);
    CalculateViewMatrix();
}

void Camera2D::SetPosition(const glm::vec2 &position)
{
    // The position is negated so that input is reverse. This moves objects around the camera
    _position = glm::vec3(-position, _position.z);
    CalculateViewMatrix();
}

void Camera2D::Move(const glm::vec2 &velocity)
{
    _position += glm::vec3(velocity, 0.0f);
    CalculateViewMatrix();
}

void Camera2D::CalculateViewMatrix(void)
{
    _view = glm::mat4(1.0f);
    _view = glm::translate(_view, _position);
    _view = _projection * _view;
}
