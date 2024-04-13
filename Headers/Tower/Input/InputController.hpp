#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Input/InputButtons.hpp"
#include "Tower/Input/InputBindings.hpp"
#include <glm/vec2.hpp>
#include <map>

namespace Tower
{
    class InputController
    {
    public:
        InputController(void);

        ~InputController(void);

        void ResetAllBindingStates(void);

        void AddKeyboardBinding(string name, InputButton button, InputButtonState state);

        void AddKeyboardBinding(InputBinding binding);

        bool IsKeyboardBindingActive(string name);

        void AddMouseBinding(string name, InputButton button, InputButtonState state);

        void AddMouseBinding(InputBinding binding);

        bool IsMouseBindingActive(string name);

        void KeyboardButtonPress(ButtonPress press);

        void MouseButtonPress(ButtonPress press);

        void SetMouseCursorPosition(const glm::vec2& position);

        const glm::vec2& GetMouseCurrentCursorPosition(void) const;

        const glm::vec2& GetMousePreviousCursorPosition(void) const;

        void AddWASDMovement(const string& forward = "move_forward",
            const string& back = "move_back",
            const string& right = "move_right",
            const string& left = "move_left");

    private:
        InputBindings _keyboardBindings;
        InputBindings _mouseBindings;
        glm::vec2 _mousePreviousPosition;
        glm::vec2 _mouseCurentPosition;

    };
    typedef std::shared_ptr<InputController> p_InputController;
}