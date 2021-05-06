#include "hspch.h"
#include "Geometry.h"

bool Geometry::IsObjectPressed(int x, int y, float color[4])
{
	struct { GLubyte red, green, blue; } pixel;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &pixel);
	float clickedColor[3];
	clickedColor[0] = (float)((float)pixel.red / 255);
	clickedColor[1] = (float)((float)pixel.green / 255);
	clickedColor[2] = (float)((float)pixel.blue / 255);
	std::cout << "Clicked Color: " << clickedColor[0] << ";" << clickedColor[1] << ";" << clickedColor[2] << std::endl;
	std::cout << "Color: " << color[0] << ";" << color[1] << ";" << color[2] << std::endl;
	if (clickedColor[0] == color[0] && clickedColor[1] == color[1] && clickedColor[2] == color[2])
	{
		return true;
	}
	return false;
}