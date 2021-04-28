#include "hspch.h"
#include "Core.h"
#include <Histroy.h>


void OnEventHappened(Histroy::Event* e)
{
	std::cout << e->ToString() << std::endl;
}


class Application
{
public:
	Application() {
		mWindow = new Histroy::Window({ "Histroy", 900, 600 });
	}
	~Application() {}

	inline void Run() {
		HS_SET_LOG_DIR(plog::warning, "F:\\DEV\\Projektek\\Histroy Engine\\Histroy\\Logs\\Logs.txt", 10000, 1);
		mWindow->Init();
		mWindow->SetCallback(OnEventHappened);
		while (!glfwWindowShouldClose(mWindow->GetWindow()))
		{
			mWindow->Appear();
		}
	}
private:
	Histroy::Window* mWindow;
};
int main()
{
	Application* application = new Application();
	application->Run();
	delete application;
	std::cin.get();
	return 0;
}