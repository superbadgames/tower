#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Input/InputButtons.hpp"
#include "Tower/Input/InputButtonState.hpp"
#include <map>
#include <glm/vec2.hpp>

namespace Tower
{
    class InputManager
    {
    public:
        ~InputManager(void);

        static shared_ptr<InputManager> Instance(void);

        void UpdateBinding(ButtonPress update);

        void ResetBindings(void);

        bool IsBindingPressed(const string& name);

        bool IsBindingHeld(const string& name);

        bool IsBindingReleased(const string& name);

        bool IsBindingPressedOrHeld(const string& name);

        void AddBinding(const string& name, Tower::InputButton button);

        void SetMouseCursorPosition(const glm::vec2& position);

        const glm::vec2& GetMouseCurrentCursorPosition(void) const;

        const glm::vec2& GetMousePreviousCursorPosition(void) const;

        void AddWASDMovement(const string& forward = "move_forward",
            const string& back = "move_back",
            const string& right = "move_right",
            const string& left = "move_left");

    private:
        static shared_ptr<InputManager> _instance;
        // TODO: Learn how to hash this string
        std::map<string, InputButton> _registeredBindings;
        std::map<string, InputButtonState> _bindingStates;
        glm::vec2 _mousePreviousPosition;
        glm::vec2 _mouseCurentPosition;

        InputManager(void);

    };
    typedef  shared_ptr<InputManager> p_InputManager;
}