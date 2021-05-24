#pragma once
#include "hspch.h"
namespace Histroy
{
	class CodeEditor
	{
	public:
		CodeEditor();
		~CodeEditor();

		void Init(Geometry* actor);
		void RenderImGui();
	private:
		//Events
		std::vector<std::shared_ptr<EventTile>> mEvents;
		std::shared_ptr<Histroy::EventTile> mSelectedEvent;

		int GetMostInstruction(); //takes the number of instructions of all events and returns the biggest
	};

}