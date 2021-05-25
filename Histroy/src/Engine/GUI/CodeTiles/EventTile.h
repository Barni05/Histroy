#pragma once
#include "hspch.h"
#include "CodeTile.h"
namespace Histroy
{
	class Geometry;
	class EventTile
	{
	public:
		EventTile(Geometry* actor, const std::string& name);
		~EventTile();
		virtual void Execute(Event& e);
		void AddTile(CodeTile* tile);
		inline std::vector<CodeTile*> GetTiles() const { return mCodeTiles; }
		inline std::string GetName() const { return mEventName; }
		inline Geometry* GetActor() const { return mActor; }
	protected:
		std::vector<CodeTile*> mCodeTiles;
		Geometry* mActor;
		std::string mEventName;
	};

}