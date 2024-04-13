#include "pch.h"
#include "Tower/Managers/Director.hpp"

#include <iostream>

using namespace Tower;

Director::Director(void) :
    _window(nullptr),
    _time{},
    _shaderManager(nullptr),
    _textureManager(nullptr)
{
}

Director::~Director(void)
{
    _shaderManager.reset();
    _textureManager.reset();
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
        _window = std::make_shared<Window>(Window{});
        _window->Init(name, width, height);
    }

    _shaderManager = std::make_shared<ShaderManager>();
    _textureManager = std::make_shared<TextureManager>();

    return true;
}


void Director::Cleanup(void)
{
    _window->Cleanup();
}


void Director::Tick(void)
{
    _time.Tick();
}


void Director::Tock(void)
{
    _time.Tock();
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
    return _time.GetDeltaClock().Time;
}

F32 Director::GetElapsedTime(void) const
{
    return _time.GetElapsedClock().Time;
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

void Director::RegisterInputWithWindow(p_InputController controller)
{
    _window->RegisterInputController(controller);
}

void Director::BeginUpdate(void)
{
    Tick();
    ProcessEvents();
}

void Director::EndUpdate(void)
{
    Tock();
}