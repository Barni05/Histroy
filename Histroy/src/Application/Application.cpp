#include "hspch.h"
#include "Core.h"
#include <GL/glew.h>
#include "Application.h"
#include <Histroy.h>

#define BIND_EVENT_FUNCTION(func) std::bind(&Application::func, this, std::placeholders::_1)
namespace Histroy
{
	bool Application::mShouldClose = false;
	bool Application::bShouldCodeEditorOpen = false;
	Application::Application() {
		mWindow = new Histroy::Window({ "Histroy", mWindowWidth, mWindowHeight });
		mCodeEditor = new Histroy::Window({ "Histroy Code Editor", mWindowWidth, mWindowHeight });
	}
	Application::~Application() { delete mWindow; delete mCodeEditor; }


	static bool bHasBeenInitialised = false; //mCodeEditor is initialised or not


	void Application::Run() {
		HS_SET_LOG_DIR(plog::warning, "F:\\DEV\\Projektek\\Histroy Engine\\Histroy\\Logs\\Logs.txt", 10000, 1);
		mWindow->Init(NULL, NULL);
		mWindow->SetCallback(BIND_EVENT_FUNCTION(OnEventHappened));
		mCodeEditor->SetCallback(BIND_EVENT_FUNCTION(OnEventHappened));
		mWindow->MakeContextCurrent();
		HistroyGui::Init(mWindow->GetWindow());
		while (!mShouldClose)
		{

			mWindow->MakeContextCurrent();
			
			HistroyGui::NewFrame();
			Menus::MainMenu();

			SetupPropertiesPage();
			SetupWorldPage();

			//Render IMGUI		  
			HistroyGui::Render();

			//Render Geometry
			HistroyRenderer::Render();

			mWindow->Update();

			if (bShouldCodeEditorOpen)
			{
				if (!bHasBeenInitialised)
				{
					mCodeEditor->Init(NULL, NULL);
					bHasBeenInitialised = true;
				}
				mCodeEditor->MakeContextCurrent();
				glBegin(GL_TRIANGLES);
				glVertex2f(-0.5f, -0.5f);
				glVertex2f(0.5f, -0.5f);
				glVertex2f(0.f, 0.5f);
				glEnd();
				mCodeEditor->Update();
			}

			glfwPollEvents();
			glClear(GL_COLOR_BUFFER_BIT);

		}
		HistroyGui::Shutdown();
		glfwTerminate();

	}

	void Application::SetupPropertiesPage()
	{
		HistroyGui::BeginRender("Properties");
		ImGui::SetWindowSize({ (float)mWindowWidth / 6, BOTTOM_VIEWPORT_DISTANCE });
		ImGui::SetWindowPos({ (float)mWindowWidth / 6, BOTTOM_VIEWPORT_DISTANCE });

		HistroyGui::EndRender();
	}

	void Application::SetupWorldPage()
	{
		HistroyGui::BeginRender("The World");
		ImGui::SetWindowSize({ (float)mWindowWidth / 6, BOTTOM_VIEWPORT_DISTANCE });
		ImGui::SetWindowPos({ 0, BOTTOM_VIEWPORT_DISTANCE });
		for (auto geometry : HistroyRenderer::sGeometries)
		{
			if (ImGui::Button(geometry->GetID().c_str(), { (float)mWindowWidth / 6, 20 }))
			{
				Application::sSelectedObject = geometry;
			}
		}
		HistroyGui::EndRender();
	}

	void Application::RenderSeparator()
	{
		float positions[]{
			(float)(mViewportWidth - mViewportWidth / 50), 0,
			(float)mViewportWidth, 0,
			mViewportWidth, mViewportHeight - 40,
			(float)(mViewportWidth - mViewportWidth / 50), mViewportHeight - 40
		};
		unsigned int indicies[]{ 0,1,2, 0, 2, 3 };
		VertexBuffer vb(8 * sizeof(float), positions);
		vb.Bind();
		IndexBuffer ib(6, indicies);

		VertexBufferLayout layout;
		layout.PushLayout<float>(2, false);

		VertexArray va;
		va.AddBuffer(vb, layout);

		Shader shader("src/Engine/GUI/Shaders/Geometry.shader");
		shader.Bind();
		shader.SetUniformMat4("u_MVP", glm::ortho(0.0f, float(Histroy::Application::mViewportWidth), 0.0f, float(Histroy::Application::mViewportHeight), -1.0f, 1.0f));
		shader.SetUniform4f("u_Color", 0.16f, 0.29f, 0.47f, 1.f);
		Renderer renderer;
		renderer.DrawElements(shader, va, ib);
	}


	bool Application::OnWindowClose(Histroy::Event& e)
	{
		mShouldClose = true;
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
		dispatcher.Dispatch<WindowClose>(BIND_EVENT_FUNCTION(OnWindowClose));
		dispatcher.Dispatch<KeyPressed>(BIND_EVENT_FUNCTION(OnKeyPressed));
		dispatcher.Dispatch<MouseButtonPressed>(BIND_EVENT_FUNCTION(OnMouseButtonPressed));
		dispatcher.Dispatch<KeyReleased>(BIND_EVENT_FUNCTION(OnKeyReleased));
		dispatcher.Dispatch<WindowResize>(BIND_EVENT_FUNCTION(OnWindowResized));
		dispatcher.Dispatch<MouseButtonReleased>(BIND_EVENT_FUNCTION(OnMouseButtonReleased));
	}

	int Application::mWindowHeight = 1080;
	int Application::mWindowWidth = 1920;
	int Application::mViewportHeight = BOTTOM_VIEWPORT_DISTANCE;
	int Application::mViewportWidth = (float)Histroy::Application::mWindowWidth / 3;

}
int main()
{
	Histroy::Application* app = new Histroy::Application();
	app->Run();
	delete app;
	std::cin.get();
	return 0;
}