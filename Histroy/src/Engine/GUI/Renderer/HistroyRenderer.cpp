#include "hspch.h"
#include "HistroyRenderer.h"
namespace Histroy
{
	void HistroyRenderer::Render(std::vector<Geometry*> geometries)
	{
		for (auto a : geometries)
		{
			a->Render();
		}	
	}
	void HistroyRenderer::RenderImGui()
	{
		if (Application::sSelectedObject)
			Application::sSelectedObject->ImGuiRender();
	}
}