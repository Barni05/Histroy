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
		KeyEvent, KeyPressed, KeyReleased,
		MouseButton, MouseButtonPressed, MouseButtonReleased, MouseScroll,
		MouseMove
	};
#define HS_EVENT_FUNCTIONS(name, type)		std::string GetName() override {return name;}\
										EventType GetType() override {return type;}
	class Event
	{
	public:
		Event(){}

		~Event() {}

		virtual std::string GetName() = 0;
		virtual EventType GetType() = 0;

		virtual std::string ToString() { return "Default event"; }
	private:
	};
}