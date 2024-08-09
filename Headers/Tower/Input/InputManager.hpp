#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Input/InputButtons.hpp"
#include <map>
#include <glm/vec2.hpp>

namespace Tower
{
    struct InputBinding
    {
        // TODO: hash this name
        string name;
        InputButton button;
        InputButtonState state;
    };

    class InputManager
    {
    public:
        ~InputManager(void);

        static shared_ptr<InputManager> Instance(void);

        void ResetActiveBindings(void);

        void UpdateBinding(ButtonPress update);

        bool IsBindingActive(string name);

        void AddBinding(const InputBinding& Binding);

        void SetMouseCursorPosition(const glm::vec2& position);

        const glm::vec2& GetMouseCurrentCursorPosition(void) const;

        const glm::vec2& GetMousePreviousCursorPosition(void) const;

        void AddWASDMovement(const string& forward = "move_forward",
            const string& back = "move_back",
            const string& right = "move_right",
            const string& left = "move_left");

    private:
        struct _BindingInfo
        {
            InputButton button;
            InputButtonState state;
        };

        static shared_ptr<InputManager> _instance;
        // TODO: Learn how to hash this string
        std::map<string, _BindingInfo> _allBindings;
        std::map<string, bool> _activeBindings;
        glm::vec2 _mousePreviousPosition;
        glm::vec2 _mouseCurentPosition;

        InputManager(void);

    };
    typedef  shared_ptr<InputManager> p_InputManager;
}