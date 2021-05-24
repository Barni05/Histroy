#include "hspch.h"
#include "EventTile.h"
#include "CodeTile.h"

namespace Histroy
{
    EventTile::EventTile(Geometry* actor, const std::string& name):mActor(actor), mEventName(name)
    {
    }
    EventTile::~EventTile()
	{
	}
    void EventTile::AddTile(CodeTile* tile)
    {
		mCodeTiles.push_back(tile);
    }
}