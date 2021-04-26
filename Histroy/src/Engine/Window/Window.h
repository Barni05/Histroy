#pragma once
#include <iostream>
#include "GLFW/glfw3.h"
namespace Histroy
{
	struct WindowData
	{
		std::string title = "Histroy Engine";
		int width, height;
	};
	class Window
	{
	public:
		Window(WindowData);
		~Window();

		void Appear();
		void Close();
	private:
		GLFWwindow* mWindow;
		WindowData mData;
		static bool sIsInitialised;
	};
}
