#include "hspch.h"
#include "Menus.h"

namespace Histroy
{
	Geometry* Application::sSelectedObject;
	void Menus::MainMenu()
	{
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
				else if (ImGui::MenuItem("Exit"))
				{
				}
				ImGui::EndMenu();
			}
			else if (ImGui::BeginMenu("Add"))
			{
				if (ImGui::MenuItem("Triangle"))
				{
					float color[4]{ 1.0f};
					Triangle* triangle = new Triangle(color);
					Application::sSelectedObject = triangle;
					HistroyRenderer::AddGeometry(triangle);
				}
				else if (ImGui::MenuItem("Square"))
				{
					float color[4]{ 1.0f };
					Square* square = new Square();
					Application::sSelectedObject = square;
					HistroyRenderer::AddGeometry(square);

				}
				ImGui::EndMenu();
			}
			else if (ImGui::BeginMenu("Open"))
			{
				if (ImGui::MenuItem("Code Editor"))
					Application::bShouldCodeEditorOpen = true;
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
	}
}
