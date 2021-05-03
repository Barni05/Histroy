#include "hspch.h"
#include "Menus.h"

namespace Histroy
{
	void Menus::MainMenu()
	{
		HistroyGui::NewFrame();
		ImGui::Begin("Menu");
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
					HistroyRenderer::AddGeometry(new Triangle(color));
				}
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
		ImGui::End();
	}
}
