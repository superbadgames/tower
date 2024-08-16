#include "pch.h"
#include "Tower/Cameras/Camera2D.hpp"

using namespace Tower;

Camera2D::Camera2D(void) :
    _target(0.0f, 0.0f, 0.0f),
    _view(1.0f),
    _projection(1.0f),
    _position(glm::vec3(0.0f, 0.0f, 3.0f)),
    _front(glm::vec3(0.0f, 0.0f, -1.0f)),
    _cameraUp(glm::vec3(0.0f, 1.0f, 0.0f))
{
    _right = glm::normalize(glm::cross(_cameraUp, _front));
}

Camera2D::~Camera2D(void)
{

}

void Camera2D::Init(F32 screenWidth, F32 screenHeight)
{
    // Left, Right, Bottom, Top, Near, Far of the screen
    // I've hard coded left, bottom, near and far. For all 2D games, these should never change.
    // If I ever need to change them, I can easily do that here.
    _projection = glm::ortho(0.0f, screenWidth, 0.0f, screenHeight, 0.1f, 100.0f);
    CalculateViewMatrix();
}


void Camera2D::SetPosition(const glm::vec2& position)
{
    _position = glm::vec3(position, _position.z);
    CalculateViewMatrix();
}


void Camera2D::CalculateViewMatrix(void)
{
    _view = glm::lookAt(_position, _position + _front, _cameraUp);
    _view = _projection * _view;
}
