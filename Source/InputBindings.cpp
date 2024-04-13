#include "pch.h"
#include "Tower/Input/InputBindings.hpp"

using namespace Tower;

InputBindings::InputBindings(void):
    _allBindings(),
    _activeBindings()
{

}

InputBindings::~InputBindings(void)
{

}

void InputBindings::ResetBindingStates(void)
{
    _activeBindings.clear();
}

void InputBindings::UpdateBinding(ButtonPress update)
{
    for (const auto& key : _allBindings)
    {
        if (key.second.button == update.button && key.second.activateState == update.state)
        {
            _activeBindings[key.first] = true;
        }
    }
}

bool InputBindings::IsBindingActive(string name)
{
    // TODO:: Test what happens if I ask for a binding that doesn't exist
    return _activeBindings[name];
}

void InputBindings::AddBinding(InputBinding binding)
{
    if (_allBindings.find(binding.name) != _allBindings.end())
    {
        string message = "Error! KeyboardInput::AddBinding was called twice for " + binding.name;
        assert(message.c_str());
    }

    _allBindings[binding.name] = _BindingInfo(binding.button, binding.activateState);
}