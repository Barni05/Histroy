#pragma once
#include <Histroy.h>
#include "Core.h"
#include "hspch.h"
namespace Histroy
{
#define BIND_EVENT_FUNCTION(func) std::bind(func, this, std::placeholders::_1)
	class Program;
	class Application
	{
	public:
		Application();
		~Application();

		void SetupPropertiesPage();
		void SetupWorldPage();
		void SetupMainMenu();

		void Run();
		static void OnEventHappened(Event& e);
		static void PlayGame();
		//Events
		static bool OnWindowClose(Event& e);
		static bool OnKeyPressed(Event& e);
		static bool OnKeyReleased(Event& e);
		static bool OnMouseButtonPressed(Event& e);
		static bool OnMouseButtonReleased(Event& e);
		static bool OnWindowResized(Event& e);
		static bool OnTick(Event& e);
		//Events


		static int* mWindowHeight, *mWindowWidth;
		static int mViewportWidth, mViewportHeight;
		static Geometry* sSelectedObject;
		static bool bShouldCodeEditorOpen;
		static Program sProgram;
		static std::vector<std::thread> sThreads;
	private:
		Histroy::Window* mWindow;
	
	};
}