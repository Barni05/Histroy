#pragma once
#include "Geometry.h"
namespace Histroy
{
	class Square : public Geometry
	{
	public:
		Square();
		~Square();
		void Init();

		void Render() override;
		Geometry* clone() override { return new Square(*this); }
		void ImGuiRender() override;
	private:
		float mInitialPositions[8];
	};

}