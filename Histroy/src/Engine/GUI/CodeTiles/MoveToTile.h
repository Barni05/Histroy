#pragma once
#include "CodeTile.h"
#include "hspch.h"
namespace Histroy
{
	class MoveToTile :
		public CodeTile
	{
	public:
		MoveToTile(int x, int y, float speed);
		~MoveToTile();

		void Execute() override;
	private:
		int mX, mY;
		float mSpeed; //speed = pixel per frame
	};

}