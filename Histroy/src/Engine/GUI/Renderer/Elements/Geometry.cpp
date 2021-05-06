#include "hspch.h"
#include "Geometry.h"

int Geometry::sGeometryNumber = 0;

bool Geometry::IsObjectPressed(int x, int y, float color[4])
{
	glFlush();
	glFinish();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	struct { GLubyte red, green, blue; } pixel;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &pixel);
	float clickedColor[3];
	clickedColor[0] = (float)((float)pixel.red / 255);
	clickedColor[1] = (float)((float)pixel.green / 255);
	clickedColor[2] = (float)((float)pixel.blue / 255);
	std::cout << "\n----------------" << std::endl;
	std::cout << "Clicked Color: " << clickedColor[0] << ";" << clickedColor[1] << ";" << clickedColor[2] << std::endl;
	std::cout << "Color: " << color[0] << ";" << color[1] << ";" << color[2];
	if ((clickedColor[0] == color[0] || abs(clickedColor[0]-color[0]) < 0.01f) && (clickedColor[1] == color[1] || abs(clickedColor[1] - color[1]) < 0.01f) && (clickedColor[2] == color[2] || abs(clickedColor[2] - color[2]) < 0.01f))
	{
		return true;
	}
	return false;
}

Geometry::Geometry():mName("Geometry")
{
	Geometry::sGeometryNumber++;
}

Geometry::~Geometry()
{
}
