// Copyright Fenerax Studios. All Rights Reserved.

#pragma once

#include <vector>
#include <functional>

namespace Axial
{
	template<typename... Params>
	class Event
	{
		typedef std::function<void(Params...)> EventHandler;

	public:
		void Register(EventHandler eventHandler)
		{
			EventHandlers.push_back(eventHandler);
		}

		void Unregister(EventHandler eventHandler)
		{
			for (size_t i = 0; i < EventHandlers.size(); i++)
			{
				if (eventHandler == EventHandlers[i])
				{
					EventHandlers.erase(EventHandlers.begin() + i);
					return;
				}
			}
		}

		void Invoke(Params... args) const
		{
			for (EventHandler eventHandler : EventHandlers)
				eventHandler(args...);
		}

		void operator()(Params... args) const { Invoke(args...); }
		void operator+=(EventHandler eventHandler) { Register(eventHandler); }
		void operator-=(EventHandler eventHandler) { Unregister(eventHandler); }

	private:
		std::vector<EventHandler> EventHandlers;
	};
}