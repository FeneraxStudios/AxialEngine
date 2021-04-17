// Copyright Fenerax Studios. All Rights Reserved.

#pragma once

#include "EventArgs.h"

namespace Axial
{
	constexpr unsigned int MOUSE_BUTTON_STATE_DOWN		= 1;
	constexpr unsigned int MOUSE_BUTTON_STATE_REPEAT	= 2;
	constexpr unsigned int MOUSE_BUTTON_STATE_UP		= 4;

	struct MouseButtonEventArgs : public EventArgs
	{
		const int Button;
		const int State;

		MouseButtonEventArgs(int button, int state) : Button(button), State(state)
		{

		}

		bool IsDown() { return (State & MOUSE_BUTTON_STATE_DOWN) > 0; }
		bool IsUp() { return (State & MOUSE_BUTTON_STATE_UP) > 0; }
	};

	struct MouseScrolledEventArgs : public EventArgs
	{
		const float DeltaX;
		const float DeltaY;

		MouseScrolledEventArgs(float deltaX, float deltaY) : DeltaX(deltaX), DeltaY(deltaY)
		{

		}
	};

	struct MouseMovedEventArgs : public EventArgs
	{
		const float X;
		const float Y;

		MouseMovedEventArgs(float x, float y) : X(x), Y(y)
		{

		}
	};
}