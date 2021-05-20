#pragma once
#include "Event.h"
namespace Histroy
{
	class Window;
	class BeginPlay : public Event
	{
	public:
		BeginPlay(Window* window) { mWindow = window; }
		~BeginPlay() {}

		HS_EVENT_FUNCTIONS("BeginPlay", EventType::Application)
	};

	class Tick : public Event
	{
	public:
		Tick(Window* window) { mWindow = window; }
		~Tick() {}

		HS_EVENT_FUNCTIONS("Tick", EventType::Application)
	};
}