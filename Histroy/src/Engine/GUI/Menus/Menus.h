#pragma once
#include "hspch.h"
namespace Histroy
{

	class Menus
	{
	public:
		static void MainMenu();
		static void AddMenu(const std::string& title);
		static void AddMenuItem(const std::string& menuTitle, const std::string& itemTitle, std::function<void()> function);

	private:
		Menus();
	};
}