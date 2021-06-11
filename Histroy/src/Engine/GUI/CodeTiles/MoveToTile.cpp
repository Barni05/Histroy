#include "hspch.h"
#include "MoveToTile.h"
namespace Histroy
{
	MoveToTile::MoveToTile(EventTile* event, glm::vec2 dest, float speed) :mSpeed(speed)
	{
		mDestination = dest;
		mTileName = "Move To";
		mEvent = event;
		mCurrLoc.x = mEvent->GetActor()->GetLocation().x;
		mCurrLoc.y = mEvent->GetActor()->GetLocation().y;
	}

	MoveToTile::~MoveToTile()
	{
		delete mEvent;
	}
    void MoveToTile::RenderImGui()
    {
		ImGui::InputFloat("X", &mDestination.x);
		ImGui::InputFloat("Y", &mDestination.y);
		ImGui::InputFloat("Speed(pixels/frame)", &mSpeed);
    }
	void MoveToTile::Execute()
	{
		std::thread t([=]() {
			glm::vec2 modifier;
			modifier = { mDestination.x > mCurrLoc.x ? 1.f : -1.f, mDestination.y > mCurrLoc.y ? 1.f : -1.f };
			while (int(mCurrLoc.x) != int(mDestination.x) && int(mCurrLoc.y) != int(mDestination.y))
			{
				mCurrLoc.x += (mSpeed*modifier.x);
				mCurrLoc.y += (mSpeed*modifier.y);
				mEvent->GetActor()->SetLocation(mCurrLoc.x, mCurrLoc.y);
				std::this_thread::sleep_for(std::chrono::microseconds(2));
			}
			ExecutableTile::QueryCurrLocation(this, mCurrLoc.x, mCurrLoc.y);
			});
		t.detach();
	}
}