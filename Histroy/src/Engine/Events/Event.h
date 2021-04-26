#pragma once
#include <iostream>
#include "Core.h"
namespace Histroy
{
	enum class EventType
	{
		NONE = 0,
		Application,
		WindowResize, WindowClose,
		KeyPressed, KeyReleased,
		MouseButton, MouseScroll,
		MouseMove
	};

	class Event
	{
	public:
		Event()
		{
			mType = EventType::NONE;
		}

		~Event() {}

		virtual std::string GetName() = 0;
		virtual EventType GetType() = 0;

		virtual std::string ToString() { HS_INFO("Default event"); }
	private:
		EventType mType;
	};
}