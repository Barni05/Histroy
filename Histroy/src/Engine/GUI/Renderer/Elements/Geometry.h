#pragma once
#include <Histroy.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"	
class Geometry
{
public:
	virtual void Render() = 0;
	virtual void ImGuiRender() {}
	virtual void UpdateTransform() {}
	virtual void OnKeyPressed(Histroy::Event& e) {}
	virtual void OnKeyReleased(Histroy::Event& e) {}
	virtual void OnMouseButtonPressed(Histroy::Event& e) {}
	virtual void OnMouseButtonReleased(Histroy::Event& e) {}

protected:
	glm::mat4 mModel, mView, mProj, mMVP;
	glm::vec3 mLocation, mRotation, mScale;

	bool IsObjectPressed(int, int, float[]);
};

