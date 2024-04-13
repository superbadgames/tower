#include "pch.h"
#include "Tower/Physics/CollisionDetection/CollisionDetector.h"
using namespace Tower;

shared_ptr<CollisionDetector> CollisionDetector::_instance = nullptr;
CollisionDetector::CollisionDetector(void)
{  }

CollisionDetector::~CollisionDetector(void)
{  }

shared_ptr<CollisionDetector> CollisionDetector::Instance(void)
{
    if (_instance == nullptr)
    {
        _instance = shared_ptr<CollisionDetector>(new CollisionDetector());
    }
    return _instance;
}

void CollisionDetector::Check(const Entity& entity)
{
    //TE::ObjectRegistry2D& dynamicObjects = TE::GameObjectManager::Instance()->GetDynamicObjects();

    // for(auto i : TE::GameObjectManager::Instance()->GetDynamicObjects())
    // {
    //     if(i.second->GetName() != object->GetName())
    //     {
    //         if(object->OverlapCheck(i.second))
    //         {
    //             object->v_OnCollide(i.second->GetName());
    //         }
    //     }
    // }
}
