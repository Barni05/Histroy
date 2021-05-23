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
		void SetupMainMenu();
		void SetupCodeEditor();

		void Run();
		void OnEventHappened(Event& e);
		//Events
		bool OnWindowClose(Event& e);
		bool OnKeyPressed(Event& e);
		bool OnKeyReleased(Event& e);
		bool OnMouseButtonPressed(Event& e);
		bool OnMouseButtonReleased(Event& e);
		bool OnWindowResized(Event& e);
		bool OnBeginPlay(Event& e);
		bool OnTick(Event& e);
		//Events

		static int mWindowHeight, mWindowWidth;
		static int mViewportWidth, mViewportHeight;
		static Geometry* sSelectedObject;
		static bool bShouldCodeEditorOpen;
	private:
		Histroy::Window* mWindow;
	
	};
}