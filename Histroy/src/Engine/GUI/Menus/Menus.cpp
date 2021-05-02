#include "hspch.h"
#include "Menus.h"

namespace Histroy
{
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
					//Render triangle
				}
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
	}
}