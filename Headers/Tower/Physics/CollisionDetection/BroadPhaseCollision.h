#pragma once

//=====Engine Includes=====
#include "pch.h"
#include "Tower/framework.h"

namespace Tower
{
    template<class PhysicsObject>
    struct PotentailContact
    {
        PhysicsObject* obj[2];
    };

    template<class BoundingVolume, class PhysicsObject>
    class Node
    {
    public:
        //==========================================================================================================================
        //
        //Constructors
        //
        //==========================================================================================================================
        Node(void)
            :
            _volume(),
            _children{ nullptr, nullptr },
            _obj(nullptr)
        {  }

        ~Node(void)
        {  }

        //==========================================================================================================================
        //
        //Functions
        //
        //==========================================================================================================================
        inline bool IsLeaf(void) const
        {
            return (_obj != nullptr);
        }



    private:
        //==========================================================================================================================
        //
        //Data
        //
        //==========================================================================================================================
        BoundingVolume  			_volume;
        Node* _children[2];
        PhysicsObject* _obj;

    };//end Class
}//end Namespace
