#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <vector>

namespace Tower
{
    class Sprite
    {
    public:
        Sprite(void);

        ~Sprite(void);

        void Init(void);

        void Draw(void);
    private:
        U32 _vao;
        U32 _vbo;
        std::vector<F32> _vertices;
    };
    typedef shared_ptr<Sprite> p_Sprite;
}