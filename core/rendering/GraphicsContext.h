// Copyright Fenerax Studios. All Rights Reserved.

#pragma once

namespace Axial
{
	class GraphicsContext
	{
	public:
		virtual ~GraphicsContext() = default;

		virtual void Initialize() = 0;
		virtual void SwapBuffers() = 0;
	};
}