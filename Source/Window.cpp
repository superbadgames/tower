#include "pch.h"
#include "Tower/Rendering/Window.hpp"

using namespace Tower;

Window::Window(void)
    :
    _mainWindow(nullptr),
    _inputController(nullptr),
    _camera(nullptr),
    _bufferWidth(800),
    _bufferHeight(600)
    // _mouseXLastPos(0.0f),
    // _mouseYLastPos(0.0f),
    // _mouseXDelta(0.0f),
    // _mouseYDelta(0.0f)
{

}


Window::~Window(void)
{}

bool Window::Init(string gameName, U32 width, U32 height)
{
    glfwSetWindowUserPointer(_mainWindow, (void*)this);
    glfwSetKeyCallback(_mainWindow, &_KeyboardInputHandler);
    glfwSetMouseButtonCallback(_mainWindow, &_MouseButtonHandler);
    glfwSetCursorPosCallback(_mainWindow, &_MouseCursorHandler);

    // Initialize GLFW
    if (!glfwInit())
    {
        glfwTerminate();
        return false;
    }

    // Setup GLFW window props
    // Opengl version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Core profile = No Backwards Compatiblity.
    glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Compatiblity override.
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    _mainWindow = glfwCreateWindow(width, height, gameName.c_str(), NULL, NULL);
    if (!_mainWindow)
    {
        // TODO: Replace with a better logging system.
        // Maybe throw?
        assert(1 && "The window is fucked man.");
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(_mainWindow);

    // Get Buffer size info
    glfwGetFramebufferSize(_mainWindow, &_bufferWidth, &_bufferHeight);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        assert(1 && "glad failed to load");
        return false;
    }

    glViewport(0, 0, _bufferWidth, _bufferHeight);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return true;
}


void Window::Cleanup(void)
{
    glfwDestroyWindow(_mainWindow);
    glfwTerminate();
}

void Window::ProcessEvents(void)
{
    //_inputController->ResetAllBindingStates();
    glfwSwapBuffers(_mainWindow);

    glfwPollEvents();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void Window::SetColor(glm::vec3& color)
{
    glClearColor(color.r, color.g, color.b, 1.0f);
}


F64 Window::GetMouseXDelta(void)
{
    // F64 delta = _mouseXDelta;
    // _mouseXDelta = 0;
    // return delta;
    return 1.0f;
}


F64 Window::GetMouseYDelta(void)
{
    // F64 delta = _mouseYDelta;
    // _mouseYDelta = 0;
    // return delta;
    return 1.0f;
}


bool Window::ShouldWindowClose(void)
{
    if (!_mainWindow)
    {
        assert(1 && "ERROR! The window is null actually");
    }
    return glfwWindowShouldClose(_mainWindow);
}


void Window::CloseWindow(void)
{
    glfwSetWindowShouldClose(_mainWindow, GL_TRUE);
}


void Window::RegisterInputController(p_InputController controller)
{
    _inputController = controller;
}

void Window::RegisterCamera(p_Camera camera)
{
    _camera = camera;
}

void Window::HideMouseCursor(void) const
{
    glfwSetInputMode(_mainWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Window::ShowMouseCursor(void) const
{
    glfwSetInputMode(_mainWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void Window::_KeyboardInputHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Window* myWindow;
    myWindow = (Window*)glfwGetWindowUserPointer(window);

    assert(myWindow != nullptr || "Error! Window::_KeyboardInputHandler failed to retrieve keyboard pointer");

    ButtonPress press;
    press.button = InputButton(key);
    press.state = InputButtonState(action);

    myWindow->GetInputController()->KeyboardButtonPress(press);
}

void Window::_MouseButtonHandler(GLFWwindow* window, int button, int action, int mods)
{
    Window* myWindow;
    myWindow = (Window*)glfwGetWindowUserPointer(window);

    assert(myWindow != nullptr || "Error! Window::_KeyboardInputHandler failed to retrieve keyboard pointer");

    ButtonPress press;
    press.button = InputButton(button);
    press.state = InputButtonState(action);

    myWindow->GetInputController()->MouseButtonPress(press);
}

void Window::_MouseCursorHandler(GLFWwindow* window, double xPos, double yPos)
{
    std::cout << "the mouse handler was called, input = (" << xPos << "," << yPos << ")" << std::endl;
    Window* myWindow;
    myWindow = (Window*)glfwGetWindowUserPointer(window);

    assert(myWindow != nullptr || "Error! Window::_KeyboardInputHandler failed to retrieve keyboard pointer");

    //camera->SetMouseCursorPosition(glm::vec2(static_cast<F32>(xPos), static_cast<F32>(yPos)));
    myWindow->GetInputController()->SetMouseCursorPosition(glm::vec2((F32)xPos, (F32)yPos));
    myWindow->GetCamera()->UpdateYawAndPitch((F32)xPos, (F32)yPos);

}


