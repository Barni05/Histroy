#pragma once
#include "Event.h"
namespace Histroy
{
	class WindowResize : public Event
	{
	public:
		WindowResize(int width, int height) : mWidth(width), mHeight(height) {}
		~WindowResize() {}

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
}