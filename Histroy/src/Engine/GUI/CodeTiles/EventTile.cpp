#include "hspch.h"
#include "EventTile.h"

void EventTile::Execute()
{
	this->mNextTile->Execute();
}

void EventTile::Render()
{
}
