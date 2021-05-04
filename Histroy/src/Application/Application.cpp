#include "hspch.h"
#include "Core.h"
#include <GL/glew.h>
#include "Application.h"
#include <Histroy.h>

#define BIND_EVENT_FUNCTION(func) std::bind(&Application::func, this, std::placeholders::_1)

namespace Histroy
{
	Application::Application(){
		mWindow = new Histroy::Window({ "Histroy", mWindowWidth, mWindowHeight });
	}
	Application::~Application() { delete mWindow; }

	void Application::Run() {
		HS_SET_LOG_DIR(plog::warning, "F:\\DEV\\Projektek\\Histroy Engine\\Histroy\\Logs\\Logs.txt", 10000, 1);
		mWindow->Init();
		mWindow->SetCallback(BIND_EVENT_FUNCTION(OnEventHappened));
		HistroyGui::Init(mWindow->GetWindow());
		while (!mShouldClose)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			Menus::MainMenu();
			HistroyGui::BeginRender("Properties");
			ImGui::SetWindowSize({ LEFT_WINDOW_INDENT, 350 });
			ImGui::SetWindowPos({ 0, float(mWindowHeight)-350 });

			//Render Geometry
			HistroyRenderer::Render();

			HistroyGui::EndRender();
			//Render IMGUI
			HistroyGui::Render();

			mWindow->Update();
		}
		HistroyGui::Shutdown();
		glfwTerminate();
	}


	bool Application::OnWindowClose(Histroy::Event& e)
	{
		mShouldClose = true;
		return true;
	}

	bool Application::OnKeyPressed(Event& e)
	{
		std::cout<<e.ToString() << std::endl;
		return true;
	}

	bool Application::OnMouseButtonPressed(Event& e)
	{
		std::cout << e.ToString() << std::endl;
		return true;
	}

	bool Application::OnWindowResized(Event& e)
	{
		mWindowHeight = dynamic_cast<WindowResize&>(e).GetHeight();
		mWindowWidth = dynamic_cast<WindowResize&>(e).GetWidth();
		return true;
	}

	void Application::OnEventHappened(Histroy::Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClose>(BIND_EVENT_FUNCTION(OnWindowClose));
		dispatcher.Dispatch<KeyPressed>(BIND_EVENT_FUNCTION(OnKeyPressed));
		dispatcher.Dispatch<MouseButtonPressed>(BIND_EVENT_FUNCTION(OnMouseButtonPressed));
		dispatcher.Dispatch<WindowResize>(BIND_EVENT_FUNCTION(OnWindowResized));
	}

	int Application::mWindowHeight = 600;
	int Application::mWindowWidth = 1200;
}

int main()
{
	Histroy::Application* app = new Histroy::Application();
	app->Run();
	delete app;
	std::cin.get();
	return 0;
}