#pragma once
#include "hspch.h"
class Geometry;
namespace Histroy
{
	class Geometry;
	class CodeTile
	{
	public:
		explicit CodeTile(Geometry* actor, const std::string& name);
		~CodeTile();
		virtual void Execute();
		inline std::string GetTileName() const { return mTileName; }
	protected:
		std::string mTileName;
		Geometry* mActor;

	};

}