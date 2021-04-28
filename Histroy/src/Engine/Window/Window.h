#pragma once
#include <iostream>
#include "GLFW/glfw3.h"
#include "Engine/Events/Event.h"

typedef std::function<void(Histroy::Event&)> EventCallback;
namespace Histroy
{
	typedef 
	struct WindowData
	{
		std::string title = "Histroy Engine";
		int width, height;
		EventCallback mCallback;
	};
	class Window
	{
	public:
		Window(WindowData);
		~Window();

		void Init();
		void Update();
		void Close();

		GLFWwindow* GetWindow() const { return mWindow; }
		EventCallback GetCallback() const { return mData.mCallback; }

		void SetCallback(EventCallback callback);

	private:
		GLFWwindow* mWindow;
		WindowData mData;
		static bool sIsInitialised;
	};

}
