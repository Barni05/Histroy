#pragma once
#include <iostream>
#include "GLFW/glfw3.h"
#include "Engine/Events/Event.h"

typedef std::function<void(Histroy::Event&)> EventCallback;
namespace Histroy
{
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

		void Init(GLFWmonitor* monitor, GLFWwindow* share);
		void MakeContextCurrent();
		static bool InitGlew();
		void Update(int x, int y, int width, int height);
		void Close();

		inline void SetSize(int x, int y) { mData.height = y; mData.width = x; }

		inline GLFWwindow* GetWindow() const { return mWindow; }
		inline EventCallback GetCallback() const { return mData.mCallback; }
		inline WindowData GetData() const { return mData; }

		void SetCallback(EventCallback callback);

	private:
		GLFWwindow* mWindow;
		WindowData mData;
		static bool sIsInitialised;
	};

}
