#include "pch.h"
#include "Tower/Input/InputManager.hpp"

#include <iostream>

using namespace Tower;

InputManager::InputManager(void) :
    _allBindings(),
    _activeBindings()
{

}

InputManager::~InputManager(void)
{
    _instance.reset();
}

shared_ptr<InputManager> InputManager::_instance = nullptr;
shared_ptr<InputManager> InputManager::Instance(void)
{
    if (_instance == nullptr)
    {
        std::cout << "No instance found, creating one now...\n";
        _instance = p_InputManager(new InputManager());
    }
    return _instance;
}

void InputManager::ResetActiveBindings(void)
{
    _activeBindings.clear();
}

void InputManager::UpdateBinding(ButtonPress update)
{
    std::cout << "InputManager::UpdateBinding was called\n";
    for (const auto& key : _allBindings)
    {
        // Any Action bound to the key pressed will be updated
        if (key.second.button == update.button && key.second.state == update.state)
        {
            _activeBindings[key.first] = true;
        }
    }
}

bool InputManager::IsBindingActive(string name)
{
    // TODO:: Test what happens if I ask for a binding that doesn't exist
    return _activeBindings[name];
}

void InputManager::AddBinding(const InputBinding& binding)
{
    if (_allBindings.find(binding.name) != _allBindings.end())
    {
        string message = "Error! KeyboardInput::AddBinding was called twice for " + binding.name;
        assert(message.c_str());
    }
    std::cout << "Add Binding called for " << binding.name << std::endl;
    _allBindings[binding.name] = _BindingInfo(binding.button, binding.state);
}

void InputManager::SetMouseCursorPosition(const glm::vec2& position)
{
    _mousePreviousPosition = _mouseCurentPosition;
    _mouseCurentPosition = position;
}

const glm::vec2& InputManager::GetMouseCurrentCursorPosition(void) const
{
    return _mouseCurentPosition;
}

const glm::vec2& InputManager::GetMousePreviousCursorPosition(void) const
{
    return _mousePreviousPosition;
}

void InputManager::AddWASDMovement(const string& forward, const string& back, const string& right, const string& left)
{
    AddBinding(InputBinding(forward, Tower::InputButton::W, Tower::InputButtonState::HOLD));
    AddBinding(InputBinding(back, Tower::InputButton::S, Tower::InputButtonState::HOLD));
    AddBinding(InputBinding(right, Tower::InputButton::D, Tower::InputButtonState::HOLD));
    AddBinding(InputBinding(left, Tower::InputButton::A, Tower::InputButtonState::HOLD));
}