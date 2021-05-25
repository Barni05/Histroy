#include "hspch.h"
#include "MoveToTile.h"
namespace Histroy
{
	MoveToTile::MoveToTile(int x, int y, float speed):mX(x), mY(y), mSpeed(speed)
	{
	}

	MoveToTile::~MoveToTile()
	{
		delete mEvent;
	}

	void MoveToTile::Execute()
	{
		int tempX, tempY;
		tempX = mEvent->GetActor()->GetLocation().x;
		tempY = mEvent->GetActor()->GetLocation().y;
		while (tempX != mX && tempY != mY)
		{
			tempX += mSpeed;
			tempY += mSpeed;
			mEvent->GetActor()->SetLocation(tempX, tempY);
		}
	}
}