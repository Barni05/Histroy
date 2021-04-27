#pragma once
#include "Core.h"
#include "Event.h"
#include <iostream>
namespace Histroy
{
	class MouseButton : public Event
	{
	public:
		inline int GetButton() const { return mButton; }

		HS_EVENT_FUNCTIONS("Mouse Button", EventType::MouseButton)
	protected:
		MouseButton(int button) :mButton(button) {}
		int mButton;
	};

	class MouseButtonPressed : public MouseButton
	{
	public:
		MouseButtonPressed(int button) :MouseButton(button) {}
		HS_EVENT_FUNCTIONS("Mouse Button Pressed", EventType::MouseButtonPressed)
		std::string ToString() override { return "Mouse Button Pressed: " + mButton; }

	};

	class MouseButtonReleased : public MouseButton
	{
	public:
		MouseButtonReleased(int button) :MouseButton(button) {}
		HS_EVENT_FUNCTIONS("Mouse Button Released", EventType::MouseButtonReleased)
		std::string ToString() override { return "Mouse Button Released: " + mButton; }
	};



	class MouseScrolled : public Event
	{
	public:
		MouseScrolled(double x, double y) :mXoffset(x), mYoffset(y) {}
		inline double GetXOffset() const { return mXoffset; }
		inline double GetYOffset() const { return mYoffset; }

		HS_EVENT_FUNCTIONS("Mouse Scrolled", EventType::MouseScroll)
		std::string ToString() override
		{
			std::stringstream ss;
			ss << "MouseScrolled: (" << GetXOffset() << "," << GetYOffset() << ")";
			return ss.str();
		}
	private:
		double mXoffset, mYoffset;
	};



	class MouseMoved : public Event
	{
	public:
		MouseMoved(float x, float y) :mX(x), mY(y) {}
		inline float GetX() const { return mX; };
		inline float GetY() const { return mY; };

		HS_EVENT_FUNCTIONS("Mouse Moved", EventType::MouseMove)
			std::string ToString() override
		{
			std::stringstream ss;
			ss << "MouseMoved: (" << GetX() << "," << GetY() << ")";
			return ss.str();
		}
	private:
		float mX, mY;
	};
}