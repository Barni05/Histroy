#include "hspch.h"
#include <Histroy.h>
int main()
{
	Histroy::Window* window = new Histroy::Window({ "Histroy Engine", 640, 480 });
	window->Appear();
	return 0;
}