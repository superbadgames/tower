#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Input/InputButtons.hpp"
#include "Tower/Input/InputManager.hpp"
#include "Tower/Components/Camera.hpp"
#include <glm/vec3.hpp>

namespace Tower
{
    // Forward declaration needed because the call back functions, the handlers cause some circular refs, I think.
    class Camera;
    typedef shared_ptr<Camera> p_Camera;

    class Window
    {
    public:
        Window(void);

        ~Window(void);

        bool Init(string gameName, U32 width, U32 height);

        void Cleanup(void);

        void ProcessEvents(void);

        void SetColor(glm::vec3& color);

        F64 GetMouseXDelta(void);

        F64 GetMouseYDelta(void);

        bool ShouldWindowClose(void);

        void CloseWindow(void);

        void RegisterCamera(p_Camera camera);

        void HideMouseCursor(void) const;

        void ShowMouseCursor(void) const;

        inline S32 GetScreenWidth(void) { return _bufferWidth; }

        inline S32 GetScreenHeight(void) { return _bufferHeight; }

        inline p_Camera GetCamera(void) { return _camera; }

    protected:
        GLFWwindow* _mainWindow;
        p_Camera _camera;
        S32 _bufferWidth;
        S32 _bufferHeight;

        static void _KeyboardInputHandler(GLFWwindow* window, int key, int scancode, int action, int mods);

        static void _MouseButtonHandler(GLFWwindow* window, int button, int action, int mods);

        static void _MouseCursorHandler(GLFWwindow* window, double xPos, double yPos);

        void _CreateCallbacks(void);

        void _WindowCleanup(void);

    };
    typedef shared_ptr<Window> p_Window;
}