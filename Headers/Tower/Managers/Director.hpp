#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Systems/TimeSystem.hpp"
#include "Tower/Rendering/Window.hpp"
// OpenGLWindow must be included before ShaderManager!
#include "Tower/Managers/ShaderManager.hpp"
#include "Tower/Managers/TextureManager.hpp"
#include "Tower/Rendering/Shader.hpp"

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

        void Tick(void);

        void Tock(void);

        void ProcessEvents(void);

        bool ShouldProgramClose(void);

        void CloseProgram(void);

        void SetWindowBackgroundColor(glm::vec3& color);

        F32 GetDeltaTime(void) const;

        F32 GetElapsedTime(void) const;

        p_Window GetWindowPointer(void) const;

        p_ShaderManager GetShaderManager(void) const;

        p_TextureManager GetTextureManager(void) const;

        void BeginUpdate(void);

        void EndUpdate(void);

    private:
        static shared_ptr<Director> _instance;

        p_Window _window;
        TimeSystem _time;
        p_ShaderManager _shaderManager;
        p_TextureManager _textureManager;

        Director(void);

    };
    typedef shared_ptr<Director> p_Director;
}