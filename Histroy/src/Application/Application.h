#pragma once
#include <Histroy.h>
#include "Core.h"
namespace Histroy
{
	class Application
	{
	public:
		Application();
		~Application();

		void Run();
		void OnEventHappened(Event& e);
		//Events
		bool OnWindowClose(Event& e);
		bool OnKeyPressed(Event& e);
		//Events
	private:
		Histroy::Window* mWindow;
		bool mShouldClose = false;
	};
}