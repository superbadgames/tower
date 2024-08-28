#include "pch.h"
#include "Tower/UI/Glyph.hpp"

using namespace Tower;

Glyph::Glyph(void) :
    _sprite(nullptr),
    _characterData()
{

}

Glyph::~Glyph(void)
{

}

void Glyph::Init(const CharacterData& characterData)
{
    _characterData = characterData;

    _sprite = std::make_shared<Sprite>();
    _sprite->Init(characterData.texture);
}

void Glyph::Draw(p_Shader shader, const Color& color)
{
    assert(_sprite != nullptr && "Glyph::Draw error! No sprite assigned to the character data\n");

    shader->SetUniform("glyph_transform", _transform.ToMatrix());

    _sprite->Draw(shader, color);
}

void Glyph::SetPosition(const glm::vec3& pos)
{
    _transform.SetPosition(pos);
}

const glm::vec3& Glyph::GetPosition(void) const
{
    return _transform.GetPosition();
}