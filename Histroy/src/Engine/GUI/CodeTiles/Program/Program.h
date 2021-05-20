#pragma once
#include "hspch.h"
class Window;
class Event;
class Program
{
public:
	void BeginPlay(Event& e);
	void Tick(Event& e);
	void KeyPressed(Event& e);
	void KeyReleased(Event& e);
	void MouseButtonPressed(Event& e);
	void MouseButtonReleased(Event& e);
private:
	
};

