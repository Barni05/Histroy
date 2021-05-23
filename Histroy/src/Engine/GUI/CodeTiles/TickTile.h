#pragma once
#include "hspch.h"
#include "EventTile.h"
class EventTile;
namespace Histroy
{
	class TickTile : public EventTile
	{
	public:
		TickTile();
		~TickTile();
		void Execute(Event& e) override;
	};

}