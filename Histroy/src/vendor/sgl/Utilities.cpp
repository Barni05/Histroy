#include "hspch.h"
#include "GL/glew.h"
#include "Utilities.h"
#include <iostream>
bool sglutils::init()
{
	if (glewInit() != GLEW_OK)
		return false;
	return true;
}
