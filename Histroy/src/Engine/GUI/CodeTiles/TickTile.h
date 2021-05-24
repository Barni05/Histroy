#pragma once
#include "hspch.h"
#include "EventTile.h"
class EventTile;
namespace Histroy
{
	class Geometry;
	class TickTile : public EventTile
	{
	public:
		TickTile(Geometry* actor, const std::string& name);
		~TickTile();
		void Execute(Event& e) override;
	};

}