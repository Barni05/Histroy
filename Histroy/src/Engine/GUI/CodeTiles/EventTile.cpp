#include "hspch.h"
#include "EventTile.h"
#include "CodeTile.h"

namespace Histroy
{
    EventTile::EventTile(Geometry* actor, const std::string& name): mEventName(name)
    {
		mActor = actor;
    }
    EventTile::~EventTile()
	{
	}
    void EventTile::Execute(Event& e)
    {
		for (auto tile : mCodeTiles)
		{
			mCurrTile = tile;
			tile->Execute();
		}
    }
    void EventTile::AddTile(CodeTile* tile)
    {
		mCodeTiles.push_back(tile);
    }
}