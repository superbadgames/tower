#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Input/InputButtonState.hpp"
#include <GLFW/glfw3.h>

namespace Tower
{
    static const U32 NUM_KEYS = 256;
    enum class InputButton
    {
        UNKNOWN = GLFW_KEY_UNKNOWN,
        NUM_0 = GLFW_KEY_0,
        NUM_1 = GLFW_KEY_1,
        NUM_2 = GLFW_KEY_2,
        NUM_3 = GLFW_KEY_3,
        NUM_4 = GLFW_KEY_4,
        NUM_5 = GLFW_KEY_5,
        NUM_6 = GLFW_KEY_6,
        NUM_7 = GLFW_KEY_7,
        NUM_8 = GLFW_KEY_8,
        NUM_9 = GLFW_KEY_9,
        A = GLFW_KEY_A,
        B = GLFW_KEY_B,
        C = GLFW_KEY_C,
        D = GLFW_KEY_D,
        E = GLFW_KEY_E,
        F = GLFW_KEY_F,
        G = GLFW_KEY_G,
        H = GLFW_KEY_H,
        I = GLFW_KEY_I,
        J = GLFW_KEY_J,
        K = GLFW_KEY_K,
        L = GLFW_KEY_L,
        M = GLFW_KEY_M,
        N = GLFW_KEY_N,
        O = GLFW_KEY_O,
        P = GLFW_KEY_P,
        Q = GLFW_KEY_Q,
        R = GLFW_KEY_R,
        S = GLFW_KEY_S,
        T = GLFW_KEY_T,
        U = GLFW_KEY_U,
        V = GLFW_KEY_V,
        W = GLFW_KEY_W,
        X = GLFW_KEY_X,
        Y = GLFW_KEY_Y,
        Z = GLFW_KEY_Z,
        SEMICOLON = GLFW_KEY_SEMICOLON,
        EQUAL = GLFW_KEY_EQUAL,
        MINUS = GLFW_KEY_MINUS,
        QUOTE = GLFW_KEY_APOSTROPHE,
        COMMA = GLFW_KEY_COMMA,
        PERIOD = GLFW_KEY_PERIOD,
        SLASH = GLFW_KEY_SLASH,
        RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET,
        LEFT_BRACKET = GLFW_KEY_LEFT_BRACKET,
        BACKSLASH = GLFW_KEY_BACKSLASH,
        BACKTICK = GLFW_KEY_GRAVE_ACCENT,
        ESCAPE = GLFW_KEY_ESCAPE,
        ENTER = GLFW_KEY_ENTER,
        SPACE = GLFW_KEY_SPACE,
        TAB = GLFW_KEY_TAB,
        BACKSPACE = GLFW_KEY_BACKSPACE,
        CAPSLOCK = GLFW_KEY_CAPS_LOCK,
        RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT,
        LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT,
        RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL,
        LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL,
        RIGHT_ALT = GLFW_KEY_RIGHT_ALT,
        LEFT_ALT = GLFW_KEY_LEFT_ALT,
        RIGHT_ARROW = GLFW_KEY_RIGHT,
        LEFT_ARROW = GLFW_KEY_LEFT,
        UP_ARROW = GLFW_KEY_UP,
        DOWN_ARROW = GLFW_KEY_DOWN,
        F1 = GLFW_KEY_F1,
        F2 = GLFW_KEY_F2,
        F3 = GLFW_KEY_F3,
        F4 = GLFW_KEY_F4,
        F5 = GLFW_KEY_F5,
        F6 = GLFW_KEY_F6,
        F7 = GLFW_KEY_F7,
        F8 = GLFW_KEY_F8,
        F9 = GLFW_KEY_F9,
        F10 = GLFW_KEY_F10,
        F11 = GLFW_KEY_F11,
        F12 = GLFW_KEY_F12,
        RIGHT_CLICK = GLFW_MOUSE_BUTTON_RIGHT,
        LEFT_CLICK = GLFW_MOUSE_BUTTON_LEFT,
        MIDDLE_CLICK = GLFW_MOUSE_BUTTON_MIDDLE
    };

    struct ButtonPress
    {
        InputButton button;
        InputButtonState state;
    };
}