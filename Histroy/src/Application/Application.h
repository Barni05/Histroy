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
		void OnEventHappened(Event& e);
		static void PlayGame();
		//Events
		bool OnWindowClose(Event& e);
		bool OnKeyPressed(Event& e);
		bool OnKeyReleased(Event& e);
		bool OnMouseButtonPressed(Event& e);
		bool OnMouseButtonReleased(Event& e);
		bool OnWindowResized(Event& e);
		bool OnTick(Event& e);
		//Events


		static int mWindowHeight, mWindowWidth;
		static int mViewportWidth, mViewportHeight;
		static Geometry* sSelectedObject;
		static bool bShouldCodeEditorOpen;
		static Program sProgram;
		static std::vector<std::thread> sThreads;
	private:
		Histroy::Window* mWindow;
	
	};
}