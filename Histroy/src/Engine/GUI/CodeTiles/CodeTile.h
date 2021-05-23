#pragma once
#include <iostream>
class CodeTile
{
public:
	CodeTile(const std::string& name);
	~CodeTile();
	virtual void Execute();
	virtual void Render() = 0;
	inline std::string GetTileName() const { return mTileName; }
protected:
	std::string mTileName;
};

