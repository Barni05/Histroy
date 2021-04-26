#include "hspch.h"
#include <Histroy.h>
#include "plog/Initializers/RollingFileInitializer.h"
int main()
{
	Histroy::Window* window = new Histroy::Window({ "Histroy Engine", 640, 480 });
	window->Appear();
	std::cin.get();
	return 0;
}