#pragma once
#include <Histroy.h>
namespace Histroy
{
	class HistroyGui
	{
	public:
		static void Init(GLFWwindow* window);
		static void NewFrame();
		static void BeginRender(const std::string& title);
		static void EndRender();
		static void Render();
		static void Shutdown();

		//Elements
		static void Button(const std::string& title);
	private:
		HistroyGui() {}
	};
}