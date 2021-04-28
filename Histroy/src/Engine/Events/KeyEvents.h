#pragma once
#include "Event.h"
namespace Histroy
{
	class KeyEvent : public Event
	{
	public:
		inline int GetKey() const { return mKey; }

		HS_EVENT_FUNCTIONS("Key Event", EventType::KeyEvent)

	protected:
		KeyEvent(int key) :mKey(key) {}
		int mKey;
	};

	class KeyPressed : public KeyEvent
	{
	public:
		KeyPressed(int key, int repeat) :KeyEvent(key), mRepeat(repeat) {}
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
		KeyReleased(int key) : KeyEvent(key) {}
		HS_EVENT_FUNCTIONS("Key Released", EventType::KeyReleased);

		std::string ToString() override 
		{ 
			std::stringstream ss;
			ss << "Key Released: " << GetKey();
			return ss.str();
		}
	};
}