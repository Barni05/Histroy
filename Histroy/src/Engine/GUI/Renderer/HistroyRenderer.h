#pragma once
#include <vector>
#include "Elements/Geometry.h"
namespace Histroy
{

	class HistroyRenderer
	{
	public:
		static void Render(std::vector<Geometry*> geometries);
		static void RenderImGui();
	};
}

