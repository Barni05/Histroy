#include "hspch.h"
#include "CodeTile.h"
namespace Histroy
{
	CodeTile::CodeTile()
	{
		mEvent = nullptr;
		mTileName = "Tile";
	}
	CodeTile::CodeTile(class EventTile* event, const std::string& name) :mEvent(event), mTileName(name)
	{
	}

	CodeTile::~CodeTile()
	{
		delete mEvent;
	}

	void CodeTile::Execute()
	{
	}
    void CodeTile::RenderImGui()
    {
    }
}