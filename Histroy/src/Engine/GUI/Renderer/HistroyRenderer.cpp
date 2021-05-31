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
	void HistroyRenderer::DeleteGeometry(Geometry* geometry)
	{
		for (int i = 0; i < sGeometries.size(); i++)
		{
			if (sGeometries[i]->GetID() == geometry->GetID())
			{
				sGeometries.erase(sGeometries.begin() + i);
			}
		}
	}
	void HistroyRenderer::RenderImGui()
	{
		if (Application::sSelectedObject)
			Application::sSelectedObject->ImGuiRender();
	}
}