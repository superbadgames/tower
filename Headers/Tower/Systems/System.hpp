#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <set>

namespace Tower
{
    class System
    {
    public:
        System(void);

        virtual ~System(void);
    };
    typedef shared_ptr<System> p_System;
}