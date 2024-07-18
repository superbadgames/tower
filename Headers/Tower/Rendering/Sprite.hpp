#pragma once

#include "pch.h"
#include "Tower/framework.h"

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
        F32 _vertices[9];
    };
    typedef shared_ptr<Sprite> p_Sprite;
}