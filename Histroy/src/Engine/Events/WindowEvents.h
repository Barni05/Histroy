#pragma once
#include "Event.h"
#include "Engine/Window/Window.h"
class Histroy::Window;
namespace Histroy
{
	class WindowResize : public Event
	{
	public:
		WindowResize(int width, int height, Window* window) : mWidth(width), mHeight(height) { mWindow = window; }
		~WindowResize() {}
		inline int GetWidth() const { return mWidth; }
		inline int GetHeight() const { return mHeight; }

		HS_EVENT_FUNCTIONS("Window Resize", EventType::WindowResize)
			std::string ToString() override
		{ 
			std::stringstream ss;
			ss << "Window Resized: (" << mWidth << ", " << mHeight << ")";
			return ss.str();
		}
	private:
		int mWidth, mHeight;
	};

	class WindowClose : public Event
	{
	public:
		WindowClose(Window* window) { mWindow = window; }
		~WindowClose() {}

		HS_EVENT_FUNCTIONS("Window Close", EventType::WindowClose)
	};
}