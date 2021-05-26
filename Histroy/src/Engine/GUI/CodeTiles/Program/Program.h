#pragma once
#include "hspch.h"
class Window;
class Event;
namespace Histroy
{
	class Program
	{
	public:
		void BeginPlay(Event& e);
		void Tick(Event& e);
		void KeyPressed(Event& e);
		void KeyReleased(Event& e);
		void MouseButtonPressed(Event& e);
		void MouseButtonReleased(Event& e);

		inline void SetActors(std::vector<Geometry*> actors) { mActors = actors; }
		inline void AddActor(Geometry* actor) { mActors.push_back(actor); }
	private:
		std::vector<Geometry*> mActors;
	};

}