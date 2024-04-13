#include "pch.h"
#include "Tower/Physics/CollisionShape/AABB.h"
using namespace Tower;

AABB::AABB(void)
    :
    _center(0.0f, 0.0f, 0.0f),
    _halfScale(0.0f, 0.0f, 0.0f)
{  }

AABB::AABB(const glm::vec3& center, F32 w, F32 h, F32 d)
    :
    _center(center),
    _halfScale(w / 2.0f, h / 2.0f, d / 2.0f)
{  }

AABB::~AABB(void)
{  }

bool AABB::TestCollision(const AABB& other) const
{
    if (real_abs(_center.x - other.GetCenter().x) > (_halfScale.x + other.GetHalfWidth()))
    {
        return false;
    }

    if (real_abs(_center.y - other.GetCenter().y) > (_halfScale.y + other.GetHalfHeight()))
    {
        return false;
    }

    if (real_abs(_center.z - other.GetCenter().z) > (_halfScale.z + other.GetHalfDepth()))
    {
        return false;
    }

    return true;
}

bool AABB::TestCollision(const glm::vec3& other) const
{
    if (real_abs(_center.x - other.x) > _halfScale.x)
    {
        return false;
    }

    if (real_abs(_center.y - other.y) > _halfScale.y)
    {
        return false;
    }

    if (real_abs(_center.z - other.z) > _halfScale.z)
    {
        return false;
    }

    return true;
}


void AABB::SetCenter(const glm::vec3& c)
{
    _center = c;
}


const glm::vec3& AABB::GetCenter(void) const
{
    return _center;
}

void AABB::SetHalfWidth(F32 width)
{
    _halfScale.x = width;
}

void AABB::SetWidth(F32 width)
{
    _halfScale.x = width / 2.0f;
}

F32 AABB::GetHalfWidth(void) const
{
    return _halfScale.x;
}

F32 AABB::GetWidth(void) const
{
    return _halfScale.x * 2.0f;
}

void AABB::SetHalfHeight(F32 height)
{
    _halfScale.y = height;
}

void AABB::SetHeight(F32 height)
{
    _halfScale.y = height / 2.0f;
}

F32 AABB::GetHalfHeight(void) const
{
    return _halfScale.y;
}

F32 AABB::GetHeight(void) const
{
    return _halfScale.y * 2.0f;
}

void AABB::SetHalfDepth(F32 depth)
{
    _halfScale.z = depth;
}

void AABB::SetDepth(F32 depth)
{
    _halfScale.z = depth / 2.0f;
}

F32 AABB::GetHalfDepth(void) const
{
    return _halfScale.z;
}

F32 AABB::GetDepth(void) const
{
    return _halfScale.z * 2.0f;
}

void AABB::SetHalfDimensions(const glm::vec3& scale)
{
    _halfScale = scale;
}

void AABB::SetDimensions(const glm::vec3& scale)
{
    _halfScale = scale / 2.0f;
}