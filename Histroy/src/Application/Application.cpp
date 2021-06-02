#include "hspch.h"
#include "Core.h"
#include <GL/glew.h>
#include "Application.h"
#include <Histroy.h>

namespace Histroy
{

	WindowDetails Application::mEditorDetails;
	Window* Application::mWindow;
	GameLayer* Application::sGameLayer;
	std::vector<Geometry*> Application::sGeometries;

	Application::Application() {
		mEditorDetails.height = 1080;
		mEditorDetails.width = 1920;
		UpdateViewports();

		mWindow = new Histroy::Window({ "Histroy", mEditorDetails.width, mEditorDetails.height });
		sGameLayer = new GameLayer();
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
			HistroyRenderer::Render(sGeometries);
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
		for (auto geometry : sGeometries)
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
			sGameLayer->PlayGame();
			});
		Menus::AddMenuItem("Add", "Triangle", []() {float color[4]{ 1.0f };
		Triangle* triangle = new Triangle(color);
		Application::sSelectedObject = triangle;
		AddGeometry(triangle); });
		Menus::AddMenuItem("Add", "Square", []() {float color[4]{ 1.0f };
		Square* square = new Square();
		Application::sSelectedObject = square;
		AddGeometry(square); });
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
		for (auto geometry : sGeometries)
			geometry->OnKeyPressed(e);
		if (dynamic_cast<Histroy::KeyPressed*>(&e)->GetKey() == GLFW_KEY_DELETE)
		{
			DeleteGeometry(sSelectedObject);
		}
		return true;
	}

	bool Application::OnMouseButtonPressed(Event& e)
	{
		for (auto geometry : sGeometries)
			geometry->OnMouseButtonPressed(e);
		return true;
	}

	bool Application::OnMouseButtonReleased(Event& e)
	{
		for (auto geometry : sGeometries)
			geometry->OnMouseButtonReleased(e);
		return true;
	}

	bool Application::OnWindowResized(Event& e)
	{
		e.GetWindow()->SetSize(dynamic_cast<WindowResize*>(&e)->GetWidth(), dynamic_cast<WindowResize*>(&e)->GetHeight());
		UpdateWindowSizes("Histroy", mEditorDetails, *dynamic_cast<WindowResize*>(&e));
		UpdateWindowSizes("Game Viewport", sGameLayer->mGameViewportDetails, *dynamic_cast<WindowResize*>(&e));
		UpdateViewports();
		return true;
	}


	bool Application::OnTick(Event& e)
	{
		return true;
	}



	bool Application::OnKeyReleased(Event& e)
	{
		for (auto geometry : sGeometries)
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

	void Application::AddGeometry(Geometry* geometry)
	{
		sGeometries.push_back(geometry);
	}
	void Application::DeleteGeometry(Geometry* geometry)
	{
		for (int i = 0; i < sGeometries.size(); i++)
		{
			if (sGeometries[i]->GetID() == geometry->GetID())
			{
				sGeometries.erase(sGeometries.begin() + i);
			}
		}
	}
	void Application::UpdateViewports()
	{

		mEditorDetails.viewportHeight = mEditorDetails.height - 20;
		mEditorDetails.viewportWidth = mEditorDetails.width - LEFT_WINDOW_INDENT;
		mEditorDetails.x = LEFT_WINDOW_INDENT;
		mEditorDetails.y = 0;
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