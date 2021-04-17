// Copyright Fenerax Studios. All Rights Reserved.

#pragma once

#include "input/Event.h"

#include "input/WindowEventArgs.h"
#include "input/KeyEventArgs.h"
#include "input/MouseEventArgs.h"

#include <string>

namespace Axial
{
	class Window
	{
	public:
		static Window* Create(std::string title = "Title", uint32_t width = 1920, uint32_t height = 1080);
		virtual ~Window() = default;

		virtual std::string GetTitle() const = 0;
		virtual void SetTitle(const std::string& title) = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual void SetDecoration(bool decoration) = 0;
		virtual void SetFullscreen(bool fullscreen) = 0;

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void PollEvents() = 0;

		virtual void Maximise() = 0;
		virtual void Restore() = 0;
		virtual void Minimise() = 0;

		Event<WindowResizedEventArgs&> Resized;
		Event<WindowClosingEventArgs&> Closing;

		Event<KeyEventArgs&> KeyDown;
		Event<KeyEventArgs&> KeyUp;
		Event<CharEventArgs&> CharEntered;

		Event<MouseButtonEventArgs&> MouseButtonDown;
		Event<MouseButtonEventArgs&> MouseButtonUp;
		Event<MouseScrolledEventArgs&> MouseScrolled;
		Event<MouseMovedEventArgs&> MouseMoved;
	};
}