#include "pch.h"
#include "Tower/Entity.hpp"

using namespace Tower;

Entity::Entity(void) : _transform(nullptr),
_model(nullptr),
_sprite(nullptr),
_shader(nullptr),
_color()
{
}

Entity::~Entity(void)
{
    _transform.reset();
    _model.reset();
    _shader.reset();
}

void Entity::Draw(const glm::mat4& viewMatrix) const
{
    glm::vec4 color = glm::vec4(0.5, 0.0f, 0.5f, 1.0f);
    _shader->SetUniform("myColor", color);
    _shader->SetUniform("testing_uniform", glm::vec3(1.0f, 1.0f, 1.0f));

    // Shader Use is called way too often I think.
    _shader->Use();
    _sprite->Draw();
    _shader->StopUse();
}

void Entity::Update(F32 delta)
{
}

void Entity::AddTransform(void)
{
    _transform = std::make_shared<Transform>();
}

void Entity::AddModel(void)
{
    assert(_shader != nullptr && "Error: You tried to call Entity::AddModel without adding a Shader first");
    _model = std::make_shared<Model>();
}

void Entity::AddModel(const string& filePath)
{
    assert(_shader != nullptr && "Error: You tried to call Entity::AddModel without adding a Shader first");
    _model = std::make_shared<Model>();
    _model->LoadFromFile(_shader, filePath);
}

void Entity::AddSprite(p_Shader shader, p_Texture texture)
{
    _shader = shader;
    _sprite = std::make_shared<Sprite>();
    _sprite->Init(texture);
}

void Entity::AddShader(void)
{
    _shader = std::make_shared<Shader>();
}

void Entity::AddShader(p_Shader shader)
{
    _shader = shader;
}

void Entity::AddTexture(const string& filepath)
{
    p_Texture texture = std::make_shared<Texture>();
    texture->Load(filepath);
    _model->SetTexture(texture);
}

void Entity::SetColor(const Color& color)
{
    _color = color;
}

const glm::vec3& Entity::GetPosition(void) const
{
    return _transform->GetPosition();
}

void Entity::SetPosition(const glm::vec3& position)
{
    _transform->SetPosition(position);
}

const glm::vec3& Entity::GetScale(void) const
{
    return _transform->GetScale();
}

void Entity::SetScale(const glm::vec3& scale)
{
    _transform->SetScale(scale);
}

const AxisAngle& Entity::GetRotation(void) const
{
    return _transform->GetRotation();
}

void Entity::SetRotation(const AxisAngle& rotation)
{
    _transform->SetRotation(rotation);
}