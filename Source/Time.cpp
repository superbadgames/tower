#include "pch.h"
#include "Tower/Systems/Time.hpp"

using namespace Tower;

Time::Time(void) :
    _lastTime(0.0),
    _currentTime(0.0),
    _deltaTime{}
{}

Time::~Time(void)
{}

void Time::Tick(void)
{
    _currentTime = static_cast<F32>(glfwGetTime());

    F32 delta = _currentTime - _lastTime;

    _deltaTime = delta;

}

void Time::Tock(void)
{
    _lastTime = _currentTime;
}

F32 Time::GetDeltaTime(void) const
{
    return _deltaTime;
}

F32 Time::GetElapsedTime(void) const
{
    return _currentTime;
}
