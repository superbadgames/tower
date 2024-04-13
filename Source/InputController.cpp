#include "pch.h"
#include "Tower/Input/InputController.hpp"

using namespace Tower;

InputController::InputController():
    _keyboardBindings(),
    _mouseBindings(),
    _mousePreviousPosition(0.0f),
    _mouseCurentPosition(0.0f)
{

}

InputController::~InputController(void)
{

}

void InputController::ResetAllBindingStates(void)
{
    _keyboardBindings.ResetBindingStates();
    _mouseBindings.ResetBindingStates();
}

void InputController::AddKeyboardBinding(string name, InputButton button, InputButtonState state)
{
    InputBinding binding;
    binding.name = name;
    binding.button = button;
    binding.activateState = state;
    AddKeyboardBinding(binding);
}

void InputController::AddKeyboardBinding(InputBinding binding)
{
    _keyboardBindings.AddBinding(binding);
}

bool InputController::IsKeyboardBindingActive(string name)
{
    return _keyboardBindings.IsBindingActive(name);
}

void InputController::AddMouseBinding(string name, InputButton button, InputButtonState state)
{
    InputBinding binding;
    binding.name = name;
    binding.button = button;
    binding.activateState = state;
    AddMouseBinding(binding);
}

void InputController::AddMouseBinding(InputBinding binding)
{
    _mouseBindings.AddBinding(binding);
}

bool InputController::IsMouseBindingActive(string name)
{
    return _mouseBindings.IsBindingActive(name);
}

void InputController::KeyboardButtonPress(ButtonPress press)
{
    _keyboardBindings.UpdateBinding(press);
}

void InputController::MouseButtonPress(ButtonPress press)
{
    _mouseBindings.UpdateBinding(press);
}

void InputController::AddWASDMovement(const string& forward, const string& back, const string& right, const string& left)
{
    AddKeyboardBinding(forward, Tower::InputButton::W, Tower::InputButtonState::HOLD);
    AddKeyboardBinding(back, Tower::InputButton::S, Tower::InputButtonState::HOLD);
    AddKeyboardBinding(right, Tower::InputButton::D, Tower::InputButtonState::HOLD);
    AddKeyboardBinding(left, Tower::InputButton::A, Tower::InputButtonState::HOLD);
}

void InputController::SetMouseCursorPosition(const glm::vec2& position)
{
    _mousePreviousPosition = _mouseCurentPosition;
    _mouseCurentPosition = position;
}

const glm::vec2& InputController::GetMouseCurrentCursorPosition(void) const
{
    return _mouseCurentPosition;
}

const glm::vec2& InputController::GetMousePreviousCursorPosition(void) const
{
    return _mousePreviousPosition;
}