#include "hspch.h"
#include "Menus.h"

namespace Histroy
{
	Geometry* Application::sSelectedObject;
	void Menus::MainMenu()
	{
		HistroyGui::NewFrame();
		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("New"))
				{

				}
				else if (ImGui::MenuItem("Close"))
				{

				}
				else if (ImGui::MenuItem("Save"))
				{

				}
				ImGui::EndMenu();
			}
			else if (ImGui::BeginMenu("Add"))
			{
				if (ImGui::MenuItem("Triangle"))
				{
					float color[4]{ 1.0f, 0.0f, 1.0f, 1.0f };
					Triangle* triangle = new Triangle(color);
					Application::sSelectedObject = triangle;
					HistroyRenderer::AddGeometry(triangle);
				}
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
	}
}
