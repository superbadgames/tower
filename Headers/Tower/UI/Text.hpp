#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/UI/Font.hpp"
#include "Tower/UI/Glyph.hpp"
#include "Tower/Rendering/Shader.hpp"
#include "Tower/Rendering/Color.hpp"
#include "Tower/Math/Transform.hpp"
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <vector>

namespace Tower
{
    class Text
    {
    public:
        Text(void);

        ~Text(void);

        void Init(p_Font font, const string& message, const Color& color);

        void Draw(const glm::mat4& projectionMatrix);

        void SetMessage(const string& message);

        void SetMessage(const string& message, const glm::vec3& position);

        void SetPosition(const glm::vec3& pos);

        void SetScale(const glm::vec3& scale);

    private:
        p_Shader _shader;
        p_Font _font;
        string _message;
        Color _color;
        Transform _transform;
        std::vector<Glyph> _glyphs;

        void _GenerateGlyphs(void);

        void _UpdateGlyphPositions(void);
    };
}