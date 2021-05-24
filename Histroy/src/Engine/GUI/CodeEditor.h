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
		std::shared_ptr<Histroy::BeginPlayTile> mBeginPlay;
		std::shared_ptr<Histroy::TickTile> mTick;
		std::shared_ptr<Histroy::EventTile> mSelectedEvent;
	};

}