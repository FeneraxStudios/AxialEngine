// Copyright Fenerax Studios. All Rights Reserved.

#pragma once

#include "system/Window.h"

struct GLFWwindow;

namespace Axial
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(std::string title, uint32_t width, uint32_t height);
		virtual ~WindowsWindow();

		virtual std::string GetTitle() const override { return Title; }
		virtual void SetTitle(const std::string& title);
		virtual unsigned int GetWidth() const override { return Width; }
		virtual unsigned int GetHeight() const override { return Height; }

		virtual void SetVSync(bool enabled) override;
		virtual void SetDecoration(bool decoration) override;
		virtual void SetFullscreen(bool fullscreen) override;

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void PollEvents() override;

		virtual void Maximise() override;
		virtual void Restore() override;
		virtual void Minimise() override;

	private:
		std::string Title = "Window";
		unsigned int Width = 1280;
		unsigned int Height = 720;

		GLFWwindow* Window;
		class GraphicsContext* Context;
	};
}