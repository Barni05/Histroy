#include "hspch.h"
#include "TickTile.h"
namespace Histroy
{
    TickTile::TickTile(Geometry* actor, const std::string& name):EventTile(actor, name)
    {
    }
	TickTile::~TickTile()
	{
	}
	void TickTile::Execute(Event& e)
	{
	}
}