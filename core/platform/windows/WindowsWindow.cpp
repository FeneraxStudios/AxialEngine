// Copyright Fenerax Studios. All Rights Reserved.

#include "WindowsWindow.h"

#include "graphics/opengl/OpenGLGraphicsContext.h"

#include <GLFW/glfw3.h>
#include <string>

namespace Axial
{
	static bool glfwInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{

	}

	Window* Window::Create(std::string title, uint32_t width, uint32_t height)
	{
		return new WindowsWindow(title, width, height);
	}

	WindowsWindow::WindowsWindow(std::string title, uint32_t width, uint32_t height) : Title(title), Width(width), Height(height), Window(nullptr), Context(nullptr)
	{
		Initialize();
	}

	WindowsWindow::~WindowsWindow()
	{

	}

	void WindowsWindow::SetTitle(const std::string& title)
	{
		Title = title;
		glfwSetWindowTitle(Window, title.c_str());
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled ? 1 : 0);
	}

	void WindowsWindow::SetDecoration(bool decoration)
	{
		glfwSetWindowAttrib(Window, GLFW_DECORATED, decoration ? GLFW_TRUE : GLFW_FALSE);
	}

	void WindowsWindow::SetFullscreen(bool fullscreen)
	{
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(monitor);
		glfwSetWindowMonitor(Window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
	}

	void WindowsWindow::Initialize()
	{
		if (!glfwInitialized)
		{
			glfwInit();
			glfwSetErrorCallback(GLFWErrorCallback);
			glfwInitialized = true;
		}

		Window = glfwCreateWindow(Width, Height, Title.c_str(), nullptr, nullptr);
		Context = new OpenGLContext(Window);
		Context->Initialize();

		glfwSetWindowUserPointer(Window, this);

		glfwSetWindowSizeCallback(Window, [](GLFWwindow* window, int width, int height)
			{
				WindowsWindow* windowsWindow = static_cast<WindowsWindow*>(glfwGetWindowUserPointer(window));
				windowsWindow->Width = width;
				windowsWindow->Height = height;
				WindowResizedEventArgs eventArgs(width, height);
				windowsWindow->Resized.Invoke(eventArgs);
			});

		glfwSetWindowCloseCallback(Window, [](GLFWwindow* window)
			{
				WindowsWindow* windowsWindow = static_cast<WindowsWindow*>(glfwGetWindowUserPointer(window));
				WindowClosingEventArgs eventArgs;
				windowsWindow->Closing.Invoke(eventArgs);
			});

		glfwSetKeyCallback(Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowsWindow* windowsWindow = static_cast<WindowsWindow*>(glfwGetWindowUserPointer(window));
				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyEventArgs eventArgs(key, KEY_STATE_DOWN, mods);
						windowsWindow->KeyDown.Invoke(eventArgs);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyEventArgs eventArgs(key, KEY_STATE_DOWN | KEY_STATE_REPEAT, mods);
						windowsWindow->KeyDown.Invoke(eventArgs);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyEventArgs eventArgs(key, KEY_STATE_UP, mods);
						windowsWindow->KeyDown.Invoke(eventArgs);
						break;
					}
				}
			});

		glfwSetCharCallback(Window, [](GLFWwindow* window, unsigned int code)
			{
				WindowsWindow* windowsWindow = static_cast<WindowsWindow*>(glfwGetWindowUserPointer(window));
				CharEventArgs eventArgs(code);
				windowsWindow->CharEntered.Invoke(eventArgs);
			});

		glfwSetMouseButtonCallback(Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowsWindow* windowsWindow = static_cast<WindowsWindow*>(glfwGetWindowUserPointer(window));
				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonEventArgs eventArgs(button, MOUSE_BUTTON_STATE_DOWN);
						windowsWindow->MouseButtonDown.Invoke(eventArgs);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonEventArgs eventArgs(button, MOUSE_BUTTON_STATE_UP);
						windowsWindow->MouseButtonUp.Invoke(eventArgs);
						break;
					}
				}
			});

		glfwSetScrollCallback(Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowsWindow* windowsWindow = static_cast<WindowsWindow*>(glfwGetWindowUserPointer(window));
				MouseScrolledEventArgs eventArgs((float)xOffset, (float)yOffset);
				windowsWindow->MouseScrolled.Invoke(eventArgs);
			});

		glfwSetCursorPosCallback(Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowsWindow* windowsWindow = static_cast<WindowsWindow*>(glfwGetWindowUserPointer(window));		
				MouseMovedEventArgs eventArgs((float)xPos, (float)yPos);
				windowsWindow->MouseMoved.Invoke(eventArgs);
			});
	}

	void WindowsWindow::Update()
	{
		Context->SwapBuffers();
	}

	void WindowsWindow::PollEvents()
	{
		glfwPollEvents();
	}

	void WindowsWindow::Maximise()
	{
		glfwMaximizeWindow(Window);
	}

	void WindowsWindow::Restore()
	{
		glfwRestoreWindow(Window);
	}

	void WindowsWindow::Minimise()
	{
		glfwIconifyWindow(Window);
	}
}