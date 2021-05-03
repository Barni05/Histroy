#include "hspch.h"
#include "HistroyRenderer.h"
namespace Histroy
{
	std::vector<Geometry*> HistroyRenderer::sGeometries;
	 
	void HistroyRenderer::Render()
	{
		for (auto a : sGeometries)
		{
			a->Render();
		}
	}
	void HistroyRenderer::AddGeometry(Geometry* geometry)
	{
		sGeometries.push_back(geometry);
	}
}