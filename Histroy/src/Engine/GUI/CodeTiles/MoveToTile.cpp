#include "hspch.h"
#include "MoveToTile.h"
namespace Histroy
{
	MoveToTile::MoveToTile(EventTile* event, int x, int y, float speed): mX(x), mY(y), mSpeed(speed)
	{
		mTileName = "Move To";
		mEvent = event;
		currLocX = mEvent->GetActor()->GetLocation().x;
		currLocY = mEvent->GetActor()->GetLocation().y;
	}

	MoveToTile::~MoveToTile()
	{
		delete mEvent;
	}
	void MoveToTile::Execute()
	{
		std::thread t([=]() {
			while (int(currLocX) != int(mX) && int(currLocY) != int(mY))
			{
				currLocX += mSpeed;
				currLocY += mSpeed;
				mEvent->GetActor()->SetLocation(currLocX, currLocY);
				std::this_thread::sleep_for(std::chrono::microseconds(2));
			}
			});
		t.detach();
	}
}