#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Sprite.hpp"
#include "Tower/UI/CharacterData.hpp"
#include "Tower/Math/Transform.hpp"

namespace Tower
{
    class Glyph
    {
    public:
        Glyph(void);

        ~Glyph(void);

        void Init(const CharacterData& characterData);

        void Draw(p_Shader shader, const Color& color);

        void SetPosition(const glm::vec3& pos);

        const glm::vec3& GetPosition(void) const;

        void SetScale(const glm::vec2& scale);

        inline void SetCharacterData(const CharacterData& data) { _characterData = data; }

        inline const CharacterData& GetCharacterData(void) const { return _characterData; }


    private:
        p_Sprite _sprite;
        CharacterData _characterData;
        Transform _transform;

    };
}