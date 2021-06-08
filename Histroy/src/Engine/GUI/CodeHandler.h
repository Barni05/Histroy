#pragma once
#include "hspch.h"
namespace Histroy
{
	class CodeHandler
	{
	public:
		CodeHandler();
		~CodeHandler();

		void Init(Geometry* actor);
		void RenderImGui();
		void EventHappened(Event& e);

		inline std::vector<std::shared_ptr<EventTile>> GetEvents() const { return mEvents; }

		//Events
		bool OnBeginPlay(Event& e);
	private:
		//Events
		std::vector<std::shared_ptr<EventTile>> mEvents;
		std::shared_ptr<Histroy::EventTile> mSelectedEvent;
		std::function<void()> mTileDetails;
		bool bDetailsOpen;

		int GetMostInstruction(); //takes the number of instructions of all events and returns the biggest
		std::shared_ptr<EventTile> GetEventByName(const std::string& name);
	};

}