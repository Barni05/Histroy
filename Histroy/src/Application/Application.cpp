#include "hspch.h"
#include "Core.h"
#include <GL/glew.h>
#include "Application.h"
#include <Histroy.h>

namespace Histroy
{

	Program Application::sProgram;
	WindowDetails Application::mEditorDetails;
	WindowDetails Application::mGameViewportDetails;
	Window* Application::mWindow;
	Window* Application::mGameViewport;

	Application::Application() {
		mEditorDetails.height = 1080;
		mEditorDetails.width = 1920;
		mEditorDetails.viewportHeight = mEditorDetails.height - 20;
		mEditorDetails.viewportWidth = mEditorDetails.width - LEFT_WINDOW_INDENT;
		mEditorDetails.x = LEFT_WINDOW_INDENT;
		mEditorDetails.y = 0;

		mGameViewportDetails.height = 1080;
		mGameViewportDetails.width = 1000;
		mGameViewportDetails.viewportHeight = mGameViewportDetails.height;
		mGameViewportDetails.viewportWidth = mGameViewportDetails.width;
		mGameViewportDetails.x = 0;
		mGameViewportDetails.y = 0;

		mWindow = new Histroy::Window({ "Histroy", mEditorDetails.width, mEditorDetails.height });
	}
	Application::~Application() { delete mWindow; }


	static bool bHasBeenInitialised = false; //mCodeEditor is initialised or not


	void Application::Run() {
		HS_SET_LOG_DIR(plog::warning, "F:\\DEV\\Projektek\\Histroy Engine\\Histroy\\Logs\\Logs.txt", 10000, 1);
		mWindow->Init(NULL, NULL);
		mWindow->SetCallback(&Application::OnEventHappened);
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
			HistroyRenderer::RenderImGui();

			//Render IMGUI		  
			HistroyGui::Render();

			mWindow->Update(mEditorDetails.x, mEditorDetails.y, mEditorDetails.viewportWidth, mEditorDetails.viewportHeight);

			glfwPollEvents();
			glClear(GL_COLOR_BUFFER_BIT);

		}
		HistroyGui::Shutdown();
		glfwTerminate();

	}

	void Application::SetupPropertiesPage()
	{
		HistroyGui::BeginRender("Properties");
		ImGui::SetWindowSize({ LEFT_WINDOW_INDENT, float(mEditorDetails.width / 2) });
		ImGui::SetWindowPos({ 0, float(mEditorDetails.height / 2) });
		HistroyGui::EndRender();
	}

	void Application::SetupWorldPage()
	{
		HistroyGui::BeginRender("The World");
		ImGui::SetWindowSize({ LEFT_WINDOW_INDENT, float(mEditorDetails.height / 2) - 20.0f });
		ImGui::SetWindowPos({ 0, 20 });
		for (auto geometry : HistroyRenderer::sGeometries)
		{
			if (ImGui::Button(geometry->GetID().c_str(), { (float)mEditorDetails.width / 6, 20 }))
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
			std::thread t2(PlayGame);
			t2.detach();
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
		e.GetWindow()->SetSize(dynamic_cast<WindowResize*>(&e)->GetWidth(), dynamic_cast<WindowResize*>(&e)->GetHeight());
		UpdateWindowSizes("Histroy", mEditorDetails, *dynamic_cast<WindowResize*>(&e));
		UpdateWindowSizes("Game Viewport", mGameViewportDetails, *dynamic_cast<WindowResize*>(&e));
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
		dispatcher.Dispatch<WindowClose>(&Application::OnWindowClose);
		dispatcher.Dispatch<KeyPressed>(&Application::OnKeyPressed);
		dispatcher.Dispatch<MouseButtonPressed>(&Application::OnMouseButtonPressed);
		dispatcher.Dispatch<KeyReleased>(&Application::OnKeyReleased);
		dispatcher.Dispatch<WindowResize>(&Application::OnWindowResized);
		dispatcher.Dispatch<MouseButtonReleased>(&Application::OnMouseButtonReleased);
	}

	void Application::PlayGame()
	{
		mGameViewport = new Window({ "Game Viewport", mGameViewportDetails.width, mGameViewportDetails.height });
		mGameViewport->SetCallback(&Application::OnEventHappened);
		mGameViewport->Init(nullptr, nullptr);
		mGameViewport->MakeContextCurrent();
		Window::InitGlew();
		while (!glfwWindowShouldClose(mGameViewport->GetWindow()))
		{

			mGameViewport->MakeContextCurrent();
			HistroyRenderer::Render();

			mGameViewport->Update(mGameViewportDetails.x, mGameViewportDetails.y, mGameViewportDetails.viewportWidth, mGameViewportDetails.viewportHeight);

			glfwPollEvents();
			glClear(GL_COLOR_BUFFER_BIT);

		}
	}

	void Application::UpdateWindowSizes(const std::string& windowName, WindowDetails& detailsToUpdate, WindowResize& rs)
	{
		if (rs.GetWindowTitle() == windowName)
		{
			std::cout << windowName << std::endl;
			detailsToUpdate.height = rs.GetHeight();
			detailsToUpdate.width = rs.GetWidth();
		}
	}

}
int main()
{
	Histroy::Application* app = new Histroy::Application();
	app->Run();
	delete app;
	std::cin.get();
	return 0;
}