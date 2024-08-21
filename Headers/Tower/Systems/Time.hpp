#pragma once

#include "pch.h"
#include "Tower/framework.h"



namespace Tower
{
    class Time
    {
    public:
        Time(void);

        ~Time(void);

        void Tick(void);

        void Tock(void);

        F32 GetDeltaTime(void) const;

        F32 GetElapsedTime(void) const;

    private:
        F32 _lastTime;
        F32 _currentTime;
        F32 _deltaTime;
    };
}