#include "hspch.h"
#include "MoveToTile.h"
namespace Histroy
{
	MoveToTile::MoveToTile(EventTile* event, int x, int y, float speed): mX(x), mY(y), mSpeed(speed)
	{
		mTileName = "Move To";
		mEvent = event;
	}

	MoveToTile::~MoveToTile()
	{
		delete mEvent;
	}

	void MoveToTile::Execute()
	{
		float tempX, tempY;
		tempX = mEvent->GetActor()->GetLocation().x;
		tempY = mEvent->GetActor()->GetLocation().y;
		while (int(tempX) != int(mX) && int(tempY)!=int(mY))
		{
			tempX += mSpeed;
			tempY += mSpeed;
			mEvent->GetActor()->SetLocation(tempX, tempY);
			mEvent->GetActor()->Render();
		}
	}
}