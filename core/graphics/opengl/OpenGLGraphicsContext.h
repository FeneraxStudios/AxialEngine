// Copyright Fenerax Studios. All Rights Reserved.

#pragma once

#include "rendering/GraphicsContext.h"

struct GLFWwindow;

namespace Axial
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Initialize() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* WindowHandle;
	};
}