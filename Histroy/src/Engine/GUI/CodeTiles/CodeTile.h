#pragma once
#include <iostream>
class CodeTile
{
public:
	CodeTile(const std::string& name);
	~CodeTile();
	virtual void Execute();
	virtual void Render() = 0;
protected:
	std::string mTileName;
	CodeTile* mNextTile;
};

