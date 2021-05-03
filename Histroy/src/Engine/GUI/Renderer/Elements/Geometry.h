#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"	
class Geometry
{
public:
	virtual void Render() = 0;
	virtual void ImGuiRender() {}
	virtual void UpdateTransform() {}
protected:
	glm::mat4 mModel, mView, mProj, mMVP;
	glm::vec3 mLocation, mRotation, mScale;
};

