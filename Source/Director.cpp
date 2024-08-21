#include "pch.h"
#include "Tower/Managers/Director.hpp"

using namespace Tower;

Director::Director(void) :
    _window(nullptr),
    _globalTime(),
    _shaderManager(nullptr),
    _textureManager(nullptr),
    _camera2D(nullptr)
{
}

Director::~Director(void)
{
    _shaderManager.reset();
    _textureManager.reset();
    _instance.reset();
}

p_Director Director::_instance = nullptr;
p_Director Director::Instance(void)
{
    if (_instance == nullptr)
    {
        _instance = p_Director(new Director());
    }
    return _instance;
}

bool Director::Init(WindowType type, string name, const U32 width, const U32 height)
{
    if (type == WindowType::OPEN_GL)
    {
        _window = std::make_shared<Window>();
        _window->Init(name, width, height);
    }

    _shaderManager = std::make_shared<ShaderManager>();
    _textureManager = std::make_shared<TextureManager>();

    _camera2D = std::make_shared<Camera2D>();
    _camera2D->Init((F32)width, (F32)height);

    return true;
}


void Director::Cleanup(void)
{
    _window->Cleanup();
}


void Director::StartFrame(void)
{
    _globalTime.Tick();
    InputManager::Instance()->ResetBindings();
    ProcessEvents();
}


void Director::EndFrame(void)
{
    _globalTime.Tock();
}


void Director::ProcessEvents(void)
{
    _window->ProcessEvents();
}


bool Director::ShouldProgramClose(void)
{
    return _window->ShouldWindowClose();
}


void Director::CloseProgram(void)
{
    _window->CloseWindow();
}

void Director::SetWindowBackgroundColor(glm::vec3& color)
{
    _window->SetColor(color);
}


F32 Director::GetDeltaTime(void) const
{
    return _globalTime.GetDeltaTime();
}

F32 Director::GetElapsedTime(void) const
{
    return _globalTime.GetElapsedTime();
}

p_Window Director::GetWindowPointer(void) const
{
    return _window;
}

p_ShaderManager Director::GetShaderManager(void) const
{
    return _shaderManager;
}

p_TextureManager Director::GetTextureManager(void) const
{
    return _textureManager;
}

p_Camera2D Director::GetCamera2D(void) const
{
    return _camera2D;
}