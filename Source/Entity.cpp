#include "pch.h"
#include "Tower/Entity.hpp"

using namespace Tower;

Entity::Entity(void) :
    _transform(nullptr),
    _model(nullptr),
    _shader(nullptr)
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
    if (_model != nullptr)
    {
        // TODO: this could be a problem. Maybe this should be decided by something else,
        // like maybe the sprite, or the model, or maybe even later. I'm not sure.
        // There has to be some stage where the shader is configured for the model
        // that is about the draw tho. The uniforms have to be set up. This will do
        // that for now.
        _shader->SetUniform("view", viewMatrix);
        _shader->SetUniform("object_color", _transform->color);
        _shader->SetUniform("model", _transform->GetTransform());

        _model->Draw();
    }
}

void Entity::Update(F32 delta)
{
    // TODO: this should be abstracted out to an UpdateSystem
    //_shader->SetUniform("model", _transform->GetTransform());

}

void Entity::AddTransform(void)
{
    _transform = std::make_shared<Transform>();
    // Default color for now
    _transform->color = glm::vec4(0.5f, 0.5f, 0.5f, 1.0f);
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
    _model = std::make_shared<Model>();
    _model->CreateSprite(_shader, texture);
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

glm::vec3 Entity::GetPosition(void) const
{
    return _transform->position;
}

void Entity::SetPostion(const glm::vec3& position)
{
    _transform->position = position;
}

const glm::vec3& Entity::GetRotationAxis(void) const
{
    return _transform->rotationAxis;
}

F32 Entity::GetRotationAngle(void) const
{
    return _transform->rotationAngle;
}

void Entity::SetRotationAxisAndAngle(F32 angle, const glm::vec3& axis)
{
    _transform->rotationAngle = angle;
    _transform->rotationAxis = axis;
}

void Entity::SetRotationAxis(const glm::vec3& axis)
{
    _transform->rotationAxis = axis;
}

void Entity::SetRotationAngle(F32 angle)
{
    _transform->rotationAngle = angle;
}

const glm::vec3& Entity::GetScale(void) const
{
    return _transform->scale;
}

void Entity::SetScale(const glm::vec3& scale)
{
    _transform->scale = scale;
}

void Entity::SetPosition(const glm::vec3& position)
{
    _transform->position = position;
}

void Entity::SetColor(const glm::vec4& color)
{
    _transform->color = color;
}

const glm::mat4& Entity::GetTransform(void) const
{
    return _transform->GetTransform();
}

p_Model Entity::GetModel(void) const
{
    if (_model != nullptr)
    {
        return _model;
    }
    return nullptr;
}
