#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"	
class Triangle
{
public:
	Triangle();

	void Render();
private:
	float mInitialPosition[6];
	glm::mat4 mProj, mView, mModel, mMVP;
};

