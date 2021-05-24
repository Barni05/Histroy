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
		mEvents.push_back(std::make_shared<BeginPlayTile>(actor, "Begin Play"));
		mEvents.push_back(std::make_shared<TickTile>(actor, "Tick"));
		mSelectedEvent = mEvents[0];
	}
	void CodeEditor::RenderImGui()
	{
		ImGui::Begin("Code Editor", (bool*)false, ImGuiWindowFlags_MenuBar);
		std::string text = "Selected Event: " + mSelectedEvent->GetName();
		ImGui::Text(text.c_str());
		ImGui::SameLine();
		for (int i = 0; i < mEvents.size(); i++)
		{
			if (ImGui::Button(mEvents[i]->GetName().c_str()))
			{
				mSelectedEvent = mEvents[i];
			}
		}
		ImGui::SameLine();
		if (ImGui::BeginTable("##table2", 2))
		{
			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			ImGui::Text("Begin Play");
			ImGui::TableNextColumn();
			ImGui::Text("Tick");
			int row = GetMostInstruction();
			for (int i = 0; i < row; i++)
			{
				ImGui::TableNextRow();
				for (int col = 0; col < mEvents.size(); col++)
				{
					ImGui::TableSetColumnIndex(col);
					std::vector<CodeTile*> currentTiles = mEvents[col]->GetTiles();
					if(currentTiles.size()!=0)
						ImGui::Text(currentTiles[i]->GetTileName().c_str());
				}
			}
			ImGui::EndTable();
		}
		ImGui::End();
	}
	int CodeEditor::GetMostInstruction()
	{
		std::vector<int> instructions;
		for (auto a : mEvents)
		{
			instructions.push_back(a->GetTiles().size());
		}

		int max = instructions[0];
		for (auto a : instructions)
		{
			if (a > max)
			{
				max = a;
			}
		}
		return max;
	}
}