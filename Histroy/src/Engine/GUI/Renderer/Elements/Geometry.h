#pragma once
#include <Histroy.h>
#include "hspch.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"	
class Geometry
{
public:
	Geometry();
	~Geometry();

	virtual void Render() = 0;
	virtual void ImGuiRender() {}
	virtual void UpdateTransform();
	virtual void OnKeyPressed(Histroy::Event& e) {}
	virtual void OnKeyReleased(Histroy::Event& e) {}
	virtual void OnMouseButtonPressed(Histroy::Event& e);
	virtual void OnMouseButtonReleased(Histroy::Event& e) {}

	inline std::string GetID() const { return mID; }
	inline std::string GetName() const { return mName; }
	inline int GetGeometryNumber() const { return mGeometryNumber; }
	int AssignIdNumber();

protected:
	glm::mat4 mModel, mView, mProj, mMVP;
	glm::vec3 mLocation, mScale;
	float mRotation;
	float mColor[4];
	std::string mName;
	std::string mID;
	int mGeometryNumber;
	char* mBufferID;

	//Events
	std::shared_ptr<Histroy::BeginPlayTile> mBeginPlay;
	std::shared_ptr<Histroy::TickTile> mTick;

	bool IsObjectPressed(int, int, float[]);
};

