#pragma once
#include <iostream>
class CodeTile
{
public:
	CodeTile(const std::string& name);
	~CodeTile();
	virtual void Execute();
	virtual void Render();
private:
	std::string mTileName;
};

