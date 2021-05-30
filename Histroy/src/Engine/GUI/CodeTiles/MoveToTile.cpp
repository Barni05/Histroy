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

		std::thread t1([=]() {
			float tempX, tempY;
			tempX = mEvent->GetActor()->GetLocation().x;
			tempY = mEvent->GetActor()->GetLocation().y;
			while (int(tempX)!=int(mX) && int(tempY) != int(mY))
			{
				tempX += mSpeed;
				tempY += mSpeed;
				//std::cout << "Angelo" << std::endl;
				mEvent->GetActor()->SetLocation(tempX, tempY);
			}
			});
		t1.detach();
	}
}