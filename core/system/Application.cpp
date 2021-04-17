// Copyright Fenerax Studios. All Rights Reserved.

#include "Application.h"

#include "Window.h"
#include "input/WindowEventArgs.h"

namespace Axial
{
	Application* Application::Instance = nullptr;

	Application::Application()
	{
		if (Instance != nullptr)
		{
			//ERROR: can only have one application
			return;
		}
		Instance = this;

		MainWindow = std::unique_ptr<Window>(Window::Create());
		MainWindow->Closing += [this](WindowClosingEventArgs& e) { OnWindowClosing(e); };
	}

	Application::~Application()
	{
		MainWindow->~Window();
	}

	int Application::Execute()
	{
		Running = true;

		while (Running)
		{
			if (MainWindow == nullptr)
				continue;

			MainWindow->PollEvents();
			MainWindow->Update();
		}
		return 0;
	}

	void Application::OnWindowClosing(WindowClosingEventArgs& e)
	{
		if (!e.Cancel)
			Running = false;
	}
}