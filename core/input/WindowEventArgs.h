// Copyright Fenerax Studios. All Rights Reserved.

#pragma once

#include "EventArgs.h"

namespace Axial
{
	struct WindowClosingEventArgs : public EventArgs
	{
		bool Cancel = false;
	};

	struct WindowResizedEventArgs : public EventArgs
	{
		const unsigned int Width, Height;

		WindowResizedEventArgs(unsigned int width, unsigned int height) : Width(width), Height(height)
		{

		}
	};
}