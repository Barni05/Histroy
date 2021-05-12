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

		void SetupPropertiesPage();
		void SetupWorldPage();

		void Run();
		void OnEventHappened(Event& e);
		//Events
		bool OnWindowClose(Event& e);
		bool OnKeyPressed(Event& e);
		bool OnKeyReleased(Event& e);
		bool OnMouseButtonPressed(Event& e);
		bool OnMouseButtonReleased(Event& e);
		bool OnWindowResized(Event& e);
		//Events

		static void CloseWindow() { mShouldClose = true; }

		static int mWindowHeight, mWindowWidth;
		static Geometry* sSelectedObject;
	private:
		Histroy::Window* mWindow;
		static bool mShouldClose;
	};
}