#include "hspch.h"
#include <Histroy.h>

int main()
{
	HS_SET_LOG_DIR(plog::warning, "F:\\DEV\\Projektek\\Histroy Engine\\Histroy\\Logs\\Logs.txt", 10000, 1);
	Histroy::WindowResize resize(640, 480);
	std::cout << resize.ToString() << std::endl;
	HS_WARNING(resize.ToString());
	std::cin.get();
	return 0;
}