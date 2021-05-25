#include "hspch.h"
#include "Menus.h"

namespace Histroy
{
	Geometry* Application::sSelectedObject;
	void Menus::AddMenu(const std::string& title)
	{
		ImGui::BeginMenu(title.c_str());
		ImGui::EndMenu();
	}
	void Menus::AddMenuItem(const std::string& menuTitle, const std::string& itemTitle, std::function<void()> function)
	{
		if (ImGui::BeginMenu(menuTitle.c_str()))
		{
			if (ImGui::MenuItem(itemTitle.c_str()))
			{
				function();
			}
			ImGui::EndMenu();
		}
	}
}
