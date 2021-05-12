
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
	void Window::Init(GLFWmonitor* monitor)
	{
		HS_ASSERT(sIsInitialised, false)
		mWindow = glfwCreateWindow(mData.width, mData.height, mData.title.c_str(), monitor, NULL);


		HS_ASSERT(mWindow, nullptr)
		glfwSetWindowUserPointer(mWindow, &mData);
		glfwMakeContextCurrent(mWindow);

		if (glewInit() != GLEW_OK)
			std::cout << "Glew Error" << std::endl;

		glfwSetWindowCloseCallback(GetWindow(), [](GLFWwindow* window) {
			Histroy::WindowData& data = *(Histroy::WindowData*)glfwGetWindowUserPointer(window);
			Histroy::WindowClose* closeEvent = new Histroy::WindowClose();
			data.mCallback(*closeEvent);
			});

		glfwSetKeyCallback(GetWindow(), [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
			case GLFW_PRESS:
			{
				Histroy::KeyPressed pressed(key, 0);
				data.mCallback(pressed);
				break;
			}
			case GLFW_RELEASE:
			{
				Histroy::KeyReleased released(key);
				data.mCallback(released);
				break;
			}
			case GLFW_REPEAT:
			{
				Histroy::KeyPressed repeat(key, 1);
				data.mCallback(repeat);
				break;
			}
			}


			});

		glfwSetWindowSizeCallback(GetWindow(), [](GLFWwindow* window, int width, int height) {
			Histroy::WindowData& data = *(Histroy::WindowData*)glfwGetWindowUserPointer(window);
			Histroy::WindowResize resize(width, height);
			data.mCallback(resize);
			});

		glfwSetCursorPosCallback(GetWindow(), [](GLFWwindow* window, double x, double y) {
			Histroy::WindowData& data = *(Histroy::WindowData*)glfwGetWindowUserPointer(window);
			Histroy::MouseMoved moved(x, y);
			data.mCallback(moved);
			});
		glfwSetScrollCallback(GetWindow(), [](GLFWwindow* window, double xoffset, double yoffset) {
			Histroy::WindowData& data = *(Histroy::WindowData*)glfwGetWindowUserPointer(window);
			Histroy::MouseScrolled scrolled(xoffset, yoffset);
			data.mCallback(scrolled);
			});

		glfwSetMouseButtonCallback(GetWindow(), [](GLFWwindow* window, int button, int action, int mods) {
			Histroy::WindowData& data = *(Histroy::WindowData*)glfwGetWindowUserPointer(window);
			double x, y;
			glfwGetCursorPos(window, &x, &y);
			switch (action)
			{
			case GLFW_PRESS:
			{
				Histroy::MouseButtonPressed  press(button, (int)x, Application::mWindowHeight - (int)y);
				data.mCallback(press);
				break;
			}
			case GLFW_RELEASE:
			{
				Histroy::MouseButtonReleased release(button, x, y);
				data.mCallback(release);
				break;
			}
			}
			});
		//INPUT CALLBACKS
	}
	void Window::Update()
	{
		glViewport(0, BOTTOM_VIEWPORT_DISTANCE, Application::mViewportWidth, Application::mViewportHeight);
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
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