#include "pch.h"
#include "Tower/UI/Text.hpp"

using namespace Tower;

Text::Text(void) :
    _shader(nullptr),
    _font(nullptr),
    _message(),
    _transform(),
    _glyphs()
{

}

Text::~Text(void)
{
    _shader.reset();
    _font.reset();
    _glyphs.clear();
}

void Text::Init(p_Font font, const string& message, const Color& color)
{
    _shader = std::make_shared<Shader>();
    _shader->Load("..\\..\\Assets\\Default\\Shaders\\ui_text_vertex.glsl", "..\\..\\Assets\\Default\\Shaders\\ui_text_fragment.glsl");

    _font = font;
    _message = message;

    for (auto character : _message)
    {
        Glyph glyph{};
        glyph.Init(_font->GetCharacterData(character));
        _glyphs.push_back(glyph);
    }
}

void Text::Draw(const glm::mat4& projectionMatrix)
{
    _shader->Use();

    _shader->SetUniform("projection", projectionMatrix);
}

void Text::SetMessage(const string& message)
{

}

void Text::SetMessage(const string& message, const glm::vec3& pos)
{
    SetPosition(pos);
    SetMessage(message);
}

void Text::SetPosition(const glm::vec3& pos)
{
    _transform.SetPosition(pos);
    _UpdateGlyphPositions();
}

void Text::SetScale(const glm::vec3& scale)
{
    _transform.SetScale(scale);
    _UpdateGlyphPositions();
}

void Text::_GenerateGlyphs(void)
{
    glm::vec3 currentPos = _transform.GetPosition();
    glm::vec3 scale = _transform.GetScale();
    for (char c : _message)
    {
        const CharacterData& characterData = _font->GetCharacterData(c);

        F32 xPosition = currentPos.x + characterData.bearing.x * scale.x;
        F32 yPosition = currentPos.y - (characterData.size.y - characterData.bearing.y) * scale.y;
    }
}

void Text::_UpdateGlyphPositions(void)
{

}