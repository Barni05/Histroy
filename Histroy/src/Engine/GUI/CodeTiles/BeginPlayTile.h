#pragma once
#include "hspch.h"
#include "EventTile.h"
namespace Histroy
{
	class BeginPlayTile : public EventTile
	{
	public:
		BeginPlayTile(Geometry* actor, const std::string& name);

		~BeginPlayTile();
		void Execute(Event& e) override;

	private:
	};

}