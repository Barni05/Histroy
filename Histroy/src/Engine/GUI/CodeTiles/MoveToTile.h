#pragma once
#include "ExecutableTile.h"
#include "hspch.h"
namespace Histroy
{
	class ExecutableTile;
	class MoveToTile : public ExecutableTile
	{
	public:
		MoveToTile(EventTile* event, glm::vec2 dest, float speed);
		~MoveToTile();
		void RenderImGui() override;
		void Execute() override;


	private:
		glm::vec2 mDestination;
		glm::vec2 mCurrLoc;
		float mSpeed; //speed = pixel per frame
	};

}