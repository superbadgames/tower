#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Input/InputButtons.hpp"
#include <map>

namespace Tower
{
    struct InputBinding
    {
        // TODO: hash this name
        string name;
        InputButton button;
        InputButtonState activateState;
    };

    class InputBindings
    {
    public:
        InputBindings(void);

        ~InputBindings(void);

        void ResetBindingStates(void);

        void UpdateBinding(ButtonPress update);

        bool IsBindingActive(string name);

        void AddBinding(InputBinding Binding);

    private:
        struct _BindingInfo
        {
            InputButton button;
            InputButtonState activateState;
        };

        // TODO: Learn how to hash this string
        std::map<string, _BindingInfo> _allBindings;
        std::map<string, bool> _activeBindings;
    };
}