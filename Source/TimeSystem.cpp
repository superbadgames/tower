#include "pch.h"
#include "Tower/Systems/TimeSystem.hpp"

using namespace Tower;

TimeSystem::TimeSystem(void):
    _lastTime(0.0),
    _currentTime(0.0),
    _deltaTime{},
    _elapsedTime{}
{}

TimeSystem::~TimeSystem(void)
{}

void TimeSystem::Tick(void)
{
    _currentTime = static_cast<F32>(glfwGetTime());
    _elapsedTime.Time = _currentTime;

    F32 delta = _currentTime - _lastTime;

    _deltaTime.Time = delta;

}

void TimeSystem::Tock(void)
{
    _lastTime = _currentTime;
}

const Clock& TimeSystem::GetDeltaClock(void) const
{
    return _deltaTime;
}

const Clock& TimeSystem::GetElapsedClock(void) const
{
    return _elapsedTime;
}
