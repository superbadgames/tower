#include "pch.h"
#include "Tower/Physics/CollisionDetection/Contact.h"
using namespace Tower;

Contact::Contact(void):
    _contactPoint(),
    _collissionNormal(),
    _penetrationDepth(),
    _collissionRestitution(),
    _friction()
{  }

Contact::~Contact(void)
{  }