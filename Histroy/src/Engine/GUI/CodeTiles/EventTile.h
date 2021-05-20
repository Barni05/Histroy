#pragma once
#include "CodeTile.h"
class EventTile :
    public CodeTile
{
public:
	void Execute() override;
	void Render() override;
};

