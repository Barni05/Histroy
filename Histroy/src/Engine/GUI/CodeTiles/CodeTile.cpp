#include "hspch.h"
#include "CodeTile.h"

CodeTile::CodeTile(const std::string& name):mTileName(name)
{
}

CodeTile::~CodeTile()
{
}

void CodeTile::Execute()
{
	if(mNextTile)
		this->mNextTile->Execute();
}
