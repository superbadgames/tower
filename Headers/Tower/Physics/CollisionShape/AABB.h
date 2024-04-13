#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace Tower
{
    class AABB
    {
    public:
        AABB(void);

        AABB(const glm::vec3& center, F32 w, F32 h, F32 d);

        ~AABB(void);

        bool TestCollision(const AABB& other) const;

        bool TestCollision(const glm::vec3& other) const;

        void SetCenter(const glm::vec3& c);

        const glm::vec3& GetCenter(void) const;

        void SetHalfWidth(F32 w);

        void SetWidth(F32 w);

        F32 GetHalfWidth(void) const;

        F32 GetWidth(void) const;

        void SetHalfHeight(F32 h);

        void SetHeight(F32 h);

        F32 GetHalfHeight(void) const;

        F32 GetHeight(void) const;

        void SetHalfDepth(F32 d);

        void SetDepth(F32 d);

        F32 GetHalfDepth(void) const;

        F32 GetDepth(void) const;

        void SetHalfDimensions(const glm::vec3& scale);

        void SetDimensions(const glm::vec3& scale);

    private:
        glm::vec3 _center;
        glm::vec3 _halfScale;

    };//end Class
    typedef shared_ptr<AABB> p_AABB;
}//end Namespace
