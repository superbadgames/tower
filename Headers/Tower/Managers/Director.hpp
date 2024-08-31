#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Systems/Time.hpp"
#include "Tower/Rendering/Window.hpp"
#include "Tower/Rendering/Shader.hpp"
#include "Tower/Cameras/Camera2D.hpp"

namespace Tower
{
    // Forward Declaration:
    // Needed to compile because the window uses the director in it's callback functions, so there are circular referenced, I think.
    class Window;
    typedef shared_ptr<Window> p_Window;

    enum class WindowType
    {
        OPEN_GL,
        VULKAN
    };

    class Director
    {
    public:
        ~Director(void);

        static shared_ptr<Director> Instance(void);

        bool Init(WindowType type = WindowType::OPEN_GL, string name = "Tower Window", const U32 width = 800, const U32 height = 600);

        void Cleanup(void);

        void StartFrame(void);

        void EndFrame(void);

        void ProcessEvents(void);

        bool ShouldProgramClose(void);

        void CloseProgram(void);

        void SetWindowBackgroundColor(glm::vec3& color);

        F32 GetDeltaTime(void) const;

        F32 GetElapsedTime(void) const;

        p_Window GetWindowPointer(void) const;

        p_Camera2D GetCamera2D(void) const;

    private:
        static shared_ptr<Director> _instance;

        p_Window _window;
        Time _globalTime;
        p_Camera2D _camera2D;

        Director(void);

    };
    typedef shared_ptr<Director> p_Director;
}