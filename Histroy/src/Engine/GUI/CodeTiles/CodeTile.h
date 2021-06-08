#pragma once
#include "hspch.h"
namespace Histroy
{
	class EventTile;
	class CodeTile
	{
	public:
		CodeTile();
		CodeTile(EventTile* event, const std::string& name);
		~CodeTile();
		virtual void Execute();
		virtual void RenderImGui();
		inline std::string GetTileName() const { return mTileName; }
	protected:
		std::string mTileName;
		EventTile* mEvent;

	};

}