#pragma once
#include "CodeTile.h"
#include "hspch.h"
namespace Histroy
{
	class ExecutableTile : public CodeTile
	{
	public:
		static void QueryCurrLocation(ExecutableTile* tile, float& x, float& y);

	};

}