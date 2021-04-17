// Copyright Fenerax Studios. All Rights Reserved.

#pragma once

#include <memory>

namespace Axial
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		int Execute();

	private:
		void OnWindowClosing(struct WindowClosingEventArgs& e);

	private:
		std::shared_ptr<class Window> MainWindow;
		bool Running = false;

	private:
		static Application* Instance;
	};
}
