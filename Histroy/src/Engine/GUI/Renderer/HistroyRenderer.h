#pragma once
#include <vector>
#include "Elements/Geometry.h"
namespace Histroy
{

	class HistroyRenderer
	{
	public:
		static void Render();
		static void AddGeometry(Geometry*);
		static void DeleteGeometry(Geometry*);
		static std::vector<Geometry*> sGeometries;
		static void RenderImGui();
	};
}

