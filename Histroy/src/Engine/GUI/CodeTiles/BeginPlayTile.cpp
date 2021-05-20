#include "hspch.h"
#include "BeginPlayTile.h"
namespace Histroy
{
	void Histroy::BeginPlayTile::Execute(Event& e)
	{
		this->mNextTile->Execute();
	}
}