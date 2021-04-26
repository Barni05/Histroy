#include "hspch.h"
#include "Window.h"
#include <GLFW/glfw3.h>
#include "Core.h"

namespace Histroy
{
	bool Window::sIsInitialised = false;
	Window::Window(WindowData data):mData(data), mWindow(nullptr)
	{
		if (!sIsInitialised)
			HS_ASSERT(glfwInit(), GLFW_FALSE)
			sIsInitialised = true;
	}

	Window::~Window()
	{
		Close();
	}
	void Window::Appear()
	{
		HS_ASSERT(sIsInitialised, false)
		mWindow = glfwCreateWindow(mData.width, mData.height, mData.title.c_str(), NULL, NULL);
		HS_ASSERT(mWindow, nullptr)
		glfwMakeContextCurrent(mWindow);

		while (!glfwWindowShouldClose(mWindow))
		{
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(mWindow);

			glfwPollEvents();
		}
	}
	void Window::Close()
	{
		glfwDestroyWindow(mWindow);
	}
}