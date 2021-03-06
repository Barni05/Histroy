#pragma once
#include <Histroy.h>
#include "Core.h"
#include "hspch.h"
namespace Histroy
{
#define BIND_EVENT_FUNCTION(func) std::bind(func, this, std::placeholders::_1)

	struct WindowDetails
	{
		int width, height;
		int viewportWidth, viewportHeight;
		int x, y;
	};
	class Program;
	class GameLayer;
	class Application
	{
	public:
		Application();
		~Application();

		static void SetupPropertiesPage();
		static void SetupWorldPage();
		static void SetupMainMenu();

		void Run();
		static void OnEventHappened(Event& e);
		static void UpdateViewports();//Updates the sizes of the viewports
		static void UpdateWindowSizes(const std::string& windowName, WindowDetails& detailsToUpdate, WindowResize& rs);
		static void AddGeometry(Geometry* geometry);
		static void DeleteGeometry(Geometry* geometry);

		//Events
		static bool OnWindowClose(Event& e);
		static bool OnKeyPressed(Event& e);
		static bool OnKeyReleased(Event& e);
		static bool OnMouseButtonPressed(Event& e);
		static bool OnMouseButtonReleased(Event& e);
		static bool OnWindowResized(Event& e);
		static bool OnTick(Event& e);
		//Events


		static WindowDetails mEditorDetails;
		static Geometry* sSelectedObject;
		static GameLayer* sGameLayer;
		static std::vector<Geometry*> sGeometries;
	private:
		static Histroy::Window* mWindow;
	
	};
}