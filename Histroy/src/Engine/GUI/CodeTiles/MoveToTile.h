#pragma once
#include "ExecutableTile.h"
#include "hspch.h"
namespace Histroy
{
	class ExecutableTile;
	class MoveToTile : public ExecutableTile
	{
	public:
		MoveToTile(EventTile* event, int x, int y, float speed);
		~MoveToTile();
		void RenderImGui() override;
		void Execute() override;


	private:
		float mX, mY;
		float currLocX, currLocY;
		float mSpeed; //speed = pixel per frame
	};

}