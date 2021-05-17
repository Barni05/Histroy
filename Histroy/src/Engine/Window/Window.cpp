
#include "hspch.h"
#include <GL/glew.h>
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
	void Window::Init(GLFWmonitor* monitor, GLFWwindow* share)
	{
		HS_ASSERT(sIsInitialised, false)
		mWindow = glfwCreateWindow(mData.width, mData.height, mData.title.c_str(), monitor, share);


		HS_ASSERT(mWindow, nullptr)
		glfwSetWindowUserPointer(mWindow, this);


		glfwSetWindowCloseCallback(GetWindow(), [](GLFWwindow* window) {
			Window* data = (Window*)glfwGetWindowUserPointer(window);
			Histroy::WindowClose* closeEvent = new Histroy::WindowClose(data);
			data->GetData().mCallback(*closeEvent);
			});

		glfwSetKeyCallback(GetWindow(), [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			Window* data = (Window*)glfwGetWindowUserPointer(window);
			switch (action)
			{
			case GLFW_PRESS:
			{
				Histroy::KeyPressed pressed(key, 0, data);
				data->GetData().mCallback(pressed);
				break;
			}
			case GLFW_RELEASE:
			{
				Histroy::KeyReleased released(key, data);
				data->GetData().mCallback(released);
				break;
			}
			case GLFW_REPEAT:
			{
				Histroy::KeyPressed repeat(key, 1, data);
				data->GetData().mCallback(repeat);
				break;
			}
			}


			});

		glfwSetWindowSizeCallback(GetWindow(), [](GLFWwindow* window, int width, int height) {
			Window* data = (Window*)glfwGetWindowUserPointer(window);
			Histroy::WindowResize resize(width, height, data);
			data->GetData().mCallback(resize);
			});

		glfwSetCursorPosCallback(GetWindow(), [](GLFWwindow* window, double x, double y) {
			Window* data = (Window*)glfwGetWindowUserPointer(window);
			Histroy::MouseMoved moved(x, y, data);
			data->GetData().mCallback(moved);
			});
		glfwSetScrollCallback(GetWindow(), [](GLFWwindow* window, double xoffset, double yoffset) {
			Window* data = (Window*)glfwGetWindowUserPointer(window);
			Histroy::MouseScrolled scrolled(xoffset, yoffset, data);
			data->GetData().mCallback(scrolled);
			});

		glfwSetMouseButtonCallback(GetWindow(), [](GLFWwindow* window, int button, int action, int mods) {
			Window* data = (Window*)glfwGetWindowUserPointer(window);
			double x, y;
			glfwGetCursorPos(window, &x, &y);
			switch (action)
			{
			case GLFW_PRESS:
			{
				Histroy::MouseButtonPressed  press(button, (int)x, Application::mWindowHeight - (int)y, data);
				data->GetData().mCallback(press);
				break;
			}
			case GLFW_RELEASE:
			{
				Histroy::MouseButtonReleased release(button, x, y, data);
				data->GetData().mCallback(release);
				break;
			}
			}
			});
		//INPUT CALLBACKS
	}
	void Window::MakeContextCurrent()
	{
		glfwMakeContextCurrent(this->GetWindow());
		if (glewInit() != GLEW_OK)
			std::cout << "Glew Error" << std::endl;
	}
	void Window::Update()
	{
		glViewport(0, BOTTOM_VIEWPORT_DISTANCE, Application::mViewportWidth, Application::mViewportHeight);
		if(mWindow)
			glfwSwapBuffers(mWindow);

	}
	void Window::Close()
	{
		glfwDestroyWindow(mWindow);
	}

	void Window::SetCallback(EventCallback callback)
	{
		mData.mCallback = callback;
	}

}