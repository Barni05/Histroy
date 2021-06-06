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
		inline void SetActor(Geometry* actor) { mActor = actor; }
		inline CodeTile* GetCurrentTile() const { return mCurrTile; }
	protected:
		std::vector<CodeTile*> mCodeTiles;
		CodeTile* mCurrTile; //The current tile that is being executed
		Geometry* mActor;
		std::string mEventName;
	};

}