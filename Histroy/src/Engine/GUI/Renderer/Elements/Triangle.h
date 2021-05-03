#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"	
#include "Geometry.h"
class Triangle : public Geometry
{
public:
	Triangle();

	void Render() override;
private:
	float mInitialPosition[6];
};

