#include "hspch.h"
#include "ExecutableTile.h"

namespace Histroy
{
    void ExecutableTile::QueryCurrLocation(ExecutableTile* tile, float& x, float& y)
    {
		for (auto actor : Application::sGeometries)
		{
			if (tile->mEvent->GetActor()->GetID() == actor->GetID())
			{
				x = actor->GetLocation().x;
				y = actor->GetLocation().y;
			}
		}
    }
}