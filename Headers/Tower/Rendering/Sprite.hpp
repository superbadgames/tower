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
        // This shouldn't be shared. The vbo data could be different
        U32 _vao;
        U32 _vbo;
        U32 _ebo;
        // Can this be static? Could all sprites share their vertices?
        std::vector<F32> _vertices;
        std::vector<U32> _indices;
    };
    typedef shared_ptr<Sprite> p_Sprite;
}