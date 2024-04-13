#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Systems/System.hpp"
#include "Tower/Components/Clock.hpp"// This is required. If it doesn't get included before <GLFW/glfw3.h>, then there is a compiler error
#include <GLFW/glfw3.h>


namespace Tower
{
    class TimeSystem : public System
    {
    public:
        TimeSystem(void);

        ~TimeSystem(void);

        void Tick(void);

        void Tock(void);

        const Clock& GetDeltaClock(void) const;

        const Clock& GetElapsedClock(void) const;

    private:
        F32 _lastTime;
        F32 _currentTime;
        Clock _deltaTime;
        Clock _elapsedTime;
    };
}