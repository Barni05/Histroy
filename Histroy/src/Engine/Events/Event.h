#pragma once
#include <iostream>
#include "Core.h"
#include "Engine/Window/Window.h"
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
	class Event
	{
		friend class EventDispatcher;
	public:
		Event():mHandled(false) {}

		~Event() {}

		virtual std::string GetName() = 0;
		virtual EventType GetType() = 0;

		virtual std::string ToString() { return GetName(); }
	private:
	protected:
		bool mHandled;
		class Window* mWindow;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFunction = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& e) : mEvent(e) {}

		template<typename T>
		bool Dispatch(EventFunction<T> function)
		{
			if (mEvent.GetType() == T::GetStaticType())
			{
				mEvent.mHandled = function(*(T*)&mEvent);
				return true;
			}
			return false;
		}
	private:
		Event& mEvent;

	};

#define HS_EVENT_FUNCTIONS(name, type)		std::string GetName() override {return name;}\
										static EventType GetStaticType() {return type;}\
										EventType GetType() override { return GetStaticType(); }
}