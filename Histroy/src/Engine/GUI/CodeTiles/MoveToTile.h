#pragma once
#include "CodeTile.h"
#include "hspch.h"
namespace Histroy
{
	class MoveToTile :
		public CodeTile
	{
	public:
		MoveToTile(EventTile* event, int x, int y, float speed);
		~MoveToTile();

		void Execute() override;
	private:
		float mX, mY;
		float mSpeed; //speed = pixel per frame
	};

}