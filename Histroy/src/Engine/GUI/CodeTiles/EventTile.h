#pragma once
#include "hspch.h"
#include "CodeTile.h"
namespace Histroy
{
	class EventTile
	{
	public:
		EventTile(Geometry* actor, const std::string& name);
		~EventTile();
		virtual void Execute(Event& e) = 0;
		void AddTile(CodeTile* tile);
		inline std::vector<CodeTile*> GetTiles() const { return mCodeTiles; }
	protected:
		std::vector<CodeTile*> mCodeTiles;
		class Geometry* mActor;
		std::string mEventName;
	};

}