#pragma once

//=====Engine Includes=====
#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Entity.hpp"


namespace Tower
{
    class CollisionDetector
    {
    protected:
        CollisionDetector(void);
    public:
        ~CollisionDetector(void);

        static shared_ptr<CollisionDetector> Instance(void);

        void Check(const Entity& entity);

    private:
        static shared_ptr<CollisionDetector> _instance;

    };//end Class
    typedef shared_ptr<CollisionDetector> p_CollisionDetector;
}
