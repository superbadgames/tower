#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Math/AxisAngle.hpp"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    class Transform
    {
    public:
        Transform(void);

        ~Transform(void);

        glm::mat4 ToMatrix(void) const;

        inline const glm::vec3& GetPosition(void) const { return _position; }

        inline void SetPosition(const glm::vec3& position) { _position = position; }

        inline const glm::vec3& GetScale(void) const { return _scale; }

        inline void SetScale(const glm::vec3& scale) { _scale = scale; }

        inline const AxisAngle& GetRotation(void) const { return _rotation; }

        inline void SetRotation(const AxisAngle& rotation) { _rotation = rotation; }

    private:
        glm::vec3 _position;
        glm::vec3 _scale;
        AxisAngle _rotation;
    };
    typedef shared_ptr<Transform> p_Transform;
};