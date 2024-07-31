#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Texture.hpp"
#include "Tower/Rendering/Color.hpp"
#include <vector>

namespace Tower
{
    class Sprite
    {
    public:
        Sprite(void);

        ~Sprite(void);

        void Init(p_Texture texture);

        void Draw(void);

        inline void SetTexture(p_Texture texture) { _texture = texture; }

    private:
        // This shouldn't be shared. The vbo data could be different
        U32 _vao;
        U32 _vbo;
        U32 _ebo;
        // Can this be static? Could all sprites share their vertices?
        std::vector<F32> _vertices;
        std::vector<F32> _uvs;
        std::vector<U32> _indices;
        p_Texture _texture;

    };
    typedef shared_ptr<Sprite> p_Sprite;
}