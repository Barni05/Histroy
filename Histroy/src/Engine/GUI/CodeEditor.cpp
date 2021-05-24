#include "hspch.h"
#include "CodeEditor.h"
namespace Histroy
{
	CodeEditor::CodeEditor()
	{
	}
	CodeEditor::~CodeEditor()
	{
	}
	void CodeEditor::Init(Geometry* actor)
	{
		mBeginPlay = std::make_shared<Histroy::BeginPlayTile>(actor, "Begin Play");
		mTick = std::make_shared<Histroy::TickTile>(actor, "Tick");
		mSelectedEvent = mBeginPlay;
	}
	void CodeEditor::RenderImGui()
	{
		ImGui::Begin("Code Editor", (bool*)false, ImGuiWindowFlags_MenuBar);
		std::string text = "Selected Event: " + mSelectedEvent->GetName();
		ImGui::Text(text.c_str());
		if (ImGui::Button("Begin Play"))
		{
			mSelectedEvent = mBeginPlay;
		}
		ImGui::End();
	}
}