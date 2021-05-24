#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"	
#include "Geometry.h"
namespace Histroy
{
	class Triangle : public Geometry
	{
	public:
		Triangle();
		Triangle(float color[4]);
		void Init();

		void Render() override;
		void ImGuiRender() override;


		void OnKeyPressed(Histroy::Event& e) override;
		void OnKeyReleased(Histroy::Event& e) override;
		void OnMouseButtonPressed(Histroy::Event& e) override;
		void OnMouseButtonReleased(Histroy::Event& e) override;
	private:
		float mInitialPosition[6];
	};

}