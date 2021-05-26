#include "hspch.h"
#include "Core.h"
#include <GL/glew.h>
#include "Application.h"
#include <Histroy.h>

namespace Histroy
{
	bool Application::bShouldCodeEditorOpen = false;
	Program Application::sProgram;

	Application::Application() {
		mWindow = new Histroy::Window({ "Histroy", mWindowWidth, mWindowHeight });
	}
	Application::~Application() { delete mWindow; }


	static bool bHasBeenInitialised = false; //mCodeEditor is initialised or not


	void Application::Run() {
		HS_SET_LOG_DIR(plog::warning, "F:\\DEV\\Projektek\\Histroy Engine\\Histroy\\Logs\\Logs.txt", 10000, 1);
		mWindow->Init(NULL, NULL);
		mWindow->SetCallback(BIND_EVENT_FUNCTION(&Application::OnEventHappened));
		mWindow->MakeContextCurrent();
		Window::InitGlew();
		HistroyGui::Init(mWindow->GetWindow());
		while (!glfwWindowShouldClose(mWindow->GetWindow()))
		{

			mWindow->MakeContextCurrent();
			
			HistroyGui::NewFrame();

			SetupPropertiesPage();
			SetupWorldPage();
			SetupMainMenu();

			//Render Geometry
			HistroyRenderer::Render();

			//Render IMGUI		  
			HistroyGui::Render();

			mWindow->Update();


			glfwPollEvents();
			glClear(GL_COLOR_BUFFER_BIT);

		}
		HistroyGui::Shutdown();
		glfwTerminate();

	}

	void Application::SetupPropertiesPage()
	{
		HistroyGui::BeginRender("Properties");
		ImGui::SetWindowSize({ LEFT_WINDOW_INDENT, float(mWindowHeight / 2) });
		ImGui::SetWindowPos({ 0, float(mWindowHeight / 2) });
		HistroyGui::EndRender();
	}

	void Application::SetupWorldPage()
	{
		HistroyGui::BeginRender("The World");
		ImGui::SetWindowSize({ LEFT_WINDOW_INDENT, float(mWindowHeight / 2) - 20.0f });
		ImGui::SetWindowPos({ 0, 20 });
		for (auto geometry : HistroyRenderer::sGeometries)
		{
			if (ImGui::Button(geometry->GetID().c_str(), { (float)mWindowWidth / 6, 20 }))
			{
				Application::sSelectedObject = geometry;
			}
		}
		HistroyGui::EndRender();
	}

	void Application::SetupMainMenu()
	{
		ImGui::BeginMainMenuBar();
		Menus::AddMenuItem("File", "Save", []() {});
		Menus::AddMenuItem("File", "Open", []() {});
		Menus::AddMenuItem("File", "Exit", []() {});
		Menus::AddMenuItem("Tools", "Play", [=]() {
			BeginPlay* bp = new BeginPlay(mWindow);
			sProgram.BeginPlay(*bp);
			});
		Menus::AddMenuItem("Add", "Triangle", []() {float color[4]{ 1.0f };
		Triangle* triangle = new Triangle(color);
		Application::sSelectedObject = triangle;
		HistroyRenderer::AddGeometry(triangle);
		Application::sProgram.AddActor(triangle); });
		Menus::AddMenuItem("Add", "Square", []() {float color[4]{ 1.0f };
		Square* square = new Square();
		Application::sSelectedObject = square;
		HistroyRenderer::AddGeometry(square);
		Application::sProgram.AddActor(square); });
		ImGui::EndMainMenuBar();
	}


	bool Application::OnWindowClose(Histroy::Event& e)
	{
		WindowClose* event = dynamic_cast<WindowClose*>(&e);
		if (event->GetWindowTitle() == "Histroy Code Editor")
		{
			//glfwDestroyWindow(mCodeEditor->GetWindow());
			bShouldCodeEditorOpen = false;
			bHasBeenInitialised = false;
		}
		return true;
	}

	bool Application::OnKeyPressed(Event& e)
	{
		for (auto geometry : HistroyRenderer::sGeometries)
			geometry->OnKeyPressed(e);
		if (dynamic_cast<Histroy::KeyPressed*>(&e)->GetKey() == GLFW_KEY_DELETE)
		{
			Histroy::HistroyRenderer::DeleteGeometry(sSelectedObject);
		}
		return true;
	}

	bool Application::OnMouseButtonPressed(Event& e)
	{
		for (auto geometry : HistroyRenderer::sGeometries)
			geometry->OnMouseButtonPressed(e);
		return true;
	}

	bool Application::OnMouseButtonReleased(Event& e)
	{
		for (auto geometry : HistroyRenderer::sGeometries)
			geometry->OnMouseButtonReleased(e);
		return true;
	}

	bool Application::OnWindowResized(Event& e)
	{
		mWindowHeight = dynamic_cast<WindowResize&>(e).GetHeight();
		mWindowWidth = dynamic_cast<WindowResize&>(e).GetWidth();
		return true;
	}


	bool Application::OnTick(Event& e)
	{
		return true;
	}


	bool Application::OnKeyReleased(Event& e)
	{
		for (auto geometry : HistroyRenderer::sGeometries)
		{
			geometry->OnKeyReleased(e);
		}
		return true;
	}

	void Application::OnEventHappened(Histroy::Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClose>(BIND_EVENT_FUNCTION(&Application::OnWindowClose));
		dispatcher.Dispatch<KeyPressed>(BIND_EVENT_FUNCTION(&Application::OnKeyPressed));
		dispatcher.Dispatch<MouseButtonPressed>(BIND_EVENT_FUNCTION(&Application::OnMouseButtonPressed));
		dispatcher.Dispatch<KeyReleased>(BIND_EVENT_FUNCTION(&Application::OnKeyReleased));
		dispatcher.Dispatch<WindowResize>(BIND_EVENT_FUNCTION(&Application::OnWindowResized));
		dispatcher.Dispatch<MouseButtonReleased>(BIND_EVENT_FUNCTION(&Application::OnMouseButtonReleased));
	}

	int Application::mWindowHeight = 1080;
	int Application::mWindowWidth = 1920;
	int Application::mViewportHeight = Application::mWindowHeight;
	int Application::mViewportWidth = Application::mWindowWidth;

}
int main()
{
	Histroy::Application* app = new Histroy::Application();
	app->Run();
	delete app;
	std::cin.get();
	return 0;
}