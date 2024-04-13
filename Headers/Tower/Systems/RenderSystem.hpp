#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Systems/System.hpp"
#include "Tower/Rendering/Model.hpp"
#include "Tower/Components/Transform.hpp"
#include "Tower/Components/Camera.hpp"
#include "Tower/Rendering/Light.hpp"
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Tower
{
    class RenderSystem: public System
    {
    public:
        RenderSystem(void);

        ~RenderSystem(void);

        void Init(void);

        void Draw(const Camera& camera);

    private:
        Camera _camera;
    };
    typedef shared_ptr<RenderSystem> p_RenderSystem;
}