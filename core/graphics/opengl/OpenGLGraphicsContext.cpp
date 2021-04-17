// Copyright Fenerax Studios. All Rights Reserved.

#include "OpenGLGraphicsContext.h"

#include <GLFW/glfw3.h>

namespace Axial
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : WindowHandle(windowHandle)
	{

	}

	void OpenGLContext::Initialize()
	{
		glfwMakeContextCurrent(WindowHandle);
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(WindowHandle);
	}
}