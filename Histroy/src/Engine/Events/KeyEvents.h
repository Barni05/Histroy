#pragma once
#include "Event.h"
#include "Engine/Window/Window.h"
namespace Histroy
{
	class Window;
	class KeyEvent : public Event
	{
	public:
		inline int GetKey() const { return mKey; }

		HS_EVENT_FUNCTIONS("Key Event", EventType::KeyEvent)

	protected:
		KeyEvent(int key) :mKey(key) {}
		int mKey;

		inline std::string GetWindowTitle() const { return mWindow->GetData().title; }
	};

	class KeyPressed : public KeyEvent
	{
	public:
		KeyPressed(int key, int repeat, Window* window) :KeyEvent(key), mRepeat(repeat) { mWindow = window; }
		inline int GetRepeat() const { return mRepeat; }
		HS_EVENT_FUNCTIONS("Key Pressed", EventType::KeyPressed)

		std::string ToString() override 
		{
			std::stringstream ss;
			ss << "Key Pressed: " << GetKey() << "(" << GetRepeat() << ")";
			return ss.str();
		}
	private:
		int mRepeat;
	};

	class KeyReleased : public KeyEvent
	{
	public:
		KeyReleased(int key, Window* window) : KeyEvent(key) { mWindow = window; }
		HS_EVENT_FUNCTIONS("Key Released", EventType::KeyReleased);

		std::string ToString() override 
		{ 
			std::stringstream ss;
			ss << "Key Released: " << GetKey();
			return ss.str();
		}
	};
}