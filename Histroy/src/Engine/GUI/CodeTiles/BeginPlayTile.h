#pragma once
#include "hspch.h"
#include "EventTile.h"
namespace Histroy
{
	class BeginPlayTile : public EventTile
	{
	public:
		void Execute(Event& e) override;

	private:
	};

}