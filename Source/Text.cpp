#include "pch.h"
#include "Tower/UI/Text.hpp"

using namespace Tower;

Text::Text(void) :
    _shader(nullptr),
    _font(nullptr),
    _message(),
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