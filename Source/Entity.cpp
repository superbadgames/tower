#include "pch.h"
#include "Tower/Entity.hpp"

using namespace Tower;

Entity::Entity(void) :
    _transform(nullptr),
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
    _sprite->Init();
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

