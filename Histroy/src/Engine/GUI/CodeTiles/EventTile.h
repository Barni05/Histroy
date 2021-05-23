#pragma once
#include "CodeTile.h"
namespace Histroy
{
	class EventTile :
		public CodeTile
	{
	public:
		virtual void Execute(Event& e) = 0;
		void Render() override;
		void AddTile(CodeTile* tile);
		inline std::vector<CodeTile*> GetTiles() const { return mCodeTiles; }
	protected:
		std::vector<CodeTile*> mCodeTiles;
	};

}