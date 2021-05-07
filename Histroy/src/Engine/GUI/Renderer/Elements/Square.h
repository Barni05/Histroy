#pragma once
#include "Geometry.h"
class Square : public Geometry
{
public:
	Square();
	~Square();
	void Init();

	void Render() override;

	void UpdateTransform() override;
private:
	float mInitialPositions[8];
};

