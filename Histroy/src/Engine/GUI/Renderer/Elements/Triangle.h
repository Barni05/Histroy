#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"	
#include "Geometry.h"
class Triangle : public Geometry
{
public:
	Triangle();
	Triangle(float color[4]);

	void Render() override;
	void ImGuiRender() override;

	void UpdateTransform() override;
private:
	float mInitialPosition[6];
	float mColor[4];
};

