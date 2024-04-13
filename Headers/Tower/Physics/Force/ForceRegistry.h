#pragma once

//=====Engine includes=====
#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/Force/ForceGenerator.h"

//=====STL includes=====
#include <vector>

namespace Tower
{
    class ForceRegistry
    {
    public:
        ForceRegistry(void);

        ~ForceRegistry(void);

        void Add(p_RigidBody2D RigidBody2D, p_ForceGenerator forceGen);

        void Add(p_RigidBody3D body, p_ForceGenerator forceGen);

        void Remove(p_RigidBody2D RigidBody2D, p_ForceGenerator forceGen);

        void Remove(p_RigidBody3D body, p_ForceGenerator forceGen);

        void Clear(void);

        void UpdateForces(void);

    private:
        struct _RigidBody2DForceRegistration
        {
            p_RigidBody2D rigidBody;
            p_ForceGenerator forceGen;

            bool operator ==(_RigidBody2DForceRegistration p)
            {
                if (p.rigidBody == rigidBody && p.forceGen == forceGen)
                    return true;
                else
                    return false;
            }
        };//end struct

        struct _RigidBody3DRegistration
        {
            p_RigidBody3D body;
            p_ForceGenerator forceGen;

            bool operator ==(_RigidBody3DRegistration b)
            {
                if (b.body == body && b.forceGen == forceGen)
                    return true;
                else
                    return false;
            }
        };

        typedef std::vector<_RigidBody2DForceRegistration> RigidBody2DRegistry;

        typedef std::vector<_RigidBody3DRegistration> RigidBody3DRegistry;

        RigidBody2DRegistry _body2DRegistrations;
        RigidBody3DRegistry _body3DRegistrations;

    };//end class
    typedef shared_ptr<ForceRegistry> p_ForceRegistry;
}//end namespacef