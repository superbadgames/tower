#pragma once

//=====Engine Includes=====
#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec4.hpp>

namespace Tower
{
    class Contact
    {
    public:
        Contact(void);

        ~Contact(void);

    private:
        glm::vec4 _contactPoint;
        glm::vec4 _collissionNormal;
        real _penetrationDepth;
        real _collissionRestitution;
        real _friction;
    };//end Class
    typedef shared_ptr<Contact> p_Contact;
}//end Namespace
