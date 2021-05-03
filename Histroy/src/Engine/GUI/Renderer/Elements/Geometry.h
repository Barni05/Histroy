#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"	
class Geometry
{
public:
	virtual void Render() = 0;
protected:
	glm::mat4 mModel, mView, mProj, mMVP;
};

