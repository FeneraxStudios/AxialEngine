// Copyright Fenerax Studios. All Rights Reserved.

#pragma once

#include "EventArgs.h"
#include "input/Keycodes.h"

namespace Axial
{
	constexpr unsigned int KEY_STATE_DOWN	= 1;
	constexpr unsigned int KEY_STATE_REPEAT	= 2;
	constexpr unsigned int KEY_STATE_UP		= 4;

	struct KeyEventArgs : public EventArgs
	{
		const int Key;
		const int State;
		const int Modifiers;

		KeyEventArgs(int key, int state, int modifiers) : Key(key), State(state), Modifiers(modifiers)
		{

		}

		bool IsDown() { return (State & (KEY_STATE_DOWN | KEY_STATE_REPEAT)) > 0; }
		bool IsRepeat() { return (State & KEY_STATE_REPEAT) > 0; }
		bool IsUp() { return (State & KEY_STATE_UP) > 0; }

		bool IsShiftDown() { return Modifiers & MODIFIER_KEY_SHIFT; }
		bool IsControlDown() { return Modifiers & MODIFIER_KEY_CONTROL; }
		bool IsAltDown() { return Modifiers & MODIFIER_KEY_ALT; }
	};

	struct CharEventArgs : public EventArgs
	{
		const char32_t Code;

		CharEventArgs(char32_t code) : Code(code)
		{

		}
	};
}