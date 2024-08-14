#include "pch.h"
#include "Tower/Input/InputManager.hpp"

#include <iostream>

using namespace Tower;

InputManager::InputManager(void) :
    _registeredBindings(),
    _bindingStates()
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
        _instance = p_InputManager(new InputManager());
    }
    return _instance;
}


void InputManager::UpdateBinding(ButtonPress update)
{
    for (const auto& key : _registeredBindings)
    {
        // Any Action bound to the key pressed will be updated
        if (key.second == update.button)
        {
            _bindingStates[key.first] = update.state;
        }
    }
}

void InputManager::ResetBindings(void)
{
    for (const auto& binding : _bindingStates)
    {
        if (_bindingStates[binding.first] != InputButtonState::PRESS && _bindingStates[binding.first] != InputButtonState::HOLD)
        {
            _bindingStates[binding.first] = InputButtonState::NONE;
        }
    }
}


bool InputManager::IsBindingPressed(const string& name)
{
    if (_bindingStates[name] == InputButtonState::PRESS)
    {
        return true;
    }
    return false;
}

bool InputManager::IsBindingHeld(const string& name)
{
    if (_bindingStates[name] == InputButtonState::HOLD)
    {
        return true;
    }
    return false;
}

bool InputManager::IsBindingReleased(const string& name)
{
    if (_bindingStates[name] == InputButtonState::RELEASE)
    {
        return true;
    }
    return false;
}

bool InputManager::IsBindingPressedOrHeld(const string& name)
{
    if (_bindingStates[name] == InputButtonState::PRESS || _bindingStates[name] == InputButtonState::HOLD)
    {
        return true;
    }
    return false;
}


void InputManager::AddBinding(const string& name, InputButton button)
{
    if (_registeredBindings.find(name) != _registeredBindings.end())
    {
        string message = "Error! KeyboardInput::AddBinding was called twice for " + name;
        assert(message.c_str());
    }

    _registeredBindings[name] = button;
    _bindingStates[name] = InputButtonState::NONE;
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
    AddBinding(forward, Tower::InputButton::W);
    AddBinding(back, Tower::InputButton::S);
    AddBinding(right, Tower::InputButton::D);
    AddBinding(left, Tower::InputButton::A);
}