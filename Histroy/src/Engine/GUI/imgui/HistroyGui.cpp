#include "hspch.h"
#include "HistroyGui.h"

namespace Histroy
{
	void HistroyGui::Init(GLFWwindow* window)
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		// Setup Platform/Renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 130");
		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
	}

	void HistroyGui::NewFrame()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void HistroyGui::BeginRender(const std::string& title)
	{
		ImGui::Begin(title.c_str());
	}

	void HistroyGui::EndRender()
	{
		ImGui::End();
	}

	void HistroyGui::Render()
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void HistroyGui::Shutdown()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}
}