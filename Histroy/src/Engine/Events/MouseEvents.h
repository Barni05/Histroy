#pragma once
#include "Core.h"
#include "Event.h"
#include "Engine/Window/Window.h"
#include <iostream>
class Histroy::Window;
namespace Histroy
{
	class MouseButton : public Event
	{
	public:
		inline int GetButton() const { return mButton; }
		inline int GetXpos() const { return mXpos; }
		inline int GetYpos() const { return mYpos; }

		HS_EVENT_FUNCTIONS("Mouse Button", EventType::MouseButton)
	protected:
		int mXpos, mYpos;
		MouseButton(int button, int x, int y) :mButton(button), mXpos(x), mYpos(y) {}
		int mButton;

		inline std::string GetWindowTitle() const { return mWindow->GetData().title; }
	};

	class MouseButtonPressed : public MouseButton
	{
	public:
		MouseButtonPressed(int button, int x, int y, Window* window) :MouseButton(button, x, y) { mWindow = window; }
		HS_EVENT_FUNCTIONS("Mouse Button Pressed", EventType::MouseButtonPressed)
		std::string ToString() override {
			std::stringstream ss;
			ss << "Mouse button pressed: " << mButton;
			return ss.str();
		}

	};

	class MouseButtonReleased : public MouseButton
	{
	public:
		MouseButtonReleased(int button, int x, int y, Window* window) :MouseButton(button, x, y) { mWindow = window; }
		HS_EVENT_FUNCTIONS("Mouse Button Released", EventType::MouseButtonReleased)
		std::string ToString() override {
			std::stringstream ss;
			ss << "Mouse button released: " << mButton;
			return ss.str();
		}
	};



	class MouseScrolled : public Event
	{
	public:
		MouseScrolled(double x, double y, Window* window) :mXoffset(x), mYoffset(y) { mWindow = window; }
		inline double GetXOffset() const { return mXoffset; }
		inline double GetYOffset() const { return mYoffset; }

		inline std::string GetWindowTitle() const { return mWindow->GetData().title; }

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
		MouseMoved(float x, float y, Window* window) :mX(x), mY(y) { mWindow = window; }
		inline float GetX() const { return mX; };
		inline float GetY() const { return mY; };

		inline std::string GetWindowTitle() const { return mWindow->GetData().title; }

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