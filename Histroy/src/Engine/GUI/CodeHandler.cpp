#include "hspch.h"
#include "CodeHandler.h"
namespace Histroy
{
	CodeHandler::CodeHandler()
	{
		bDetailsOpen = false;
	}
	CodeHandler::~CodeHandler()
	{
	}
	void CodeHandler::Init(Geometry* actor)
	{
		mEvents.clear();
		mEvents.push_back(std::make_shared<BeginPlayTile>(actor, "Begin Play"));
		mEvents.push_back(std::make_shared<TickTile>(actor, "Tick"));
		mSelectedEvent = mEvents[0];
	}
	void CodeHandler::RenderImGui()
	{
		ImGui::Begin("Code Editor", (bool*)false, ImGuiWindowFlags_MenuBar);
		//Menu
		ImGui::BeginMenuBar();
		Menus::AddMenuItem("Mobility", "Move To", [=]() {
			MoveToTile* tile = new MoveToTile(mSelectedEvent.get(), {0.f, 0.f}, 0.1f);
			mTileDetails = std::bind(&CodeTile::RenderImGui, tile);
			bDetailsOpen = true;
			mSelectedEvent->AddTile(tile);
			});
		if (mTileDetails && bDetailsOpen)
		{
			ImGui::OpenPopup("Details");
			if (ImGui::BeginPopupModal("Details", &bDetailsOpen))
			{
				mTileDetails();
				ImGui::EndPopup();
			}
		}
		ImGui::EndMenuBar();
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
			//displaying code in a  table
			int row = GetMostInstruction();
			for (int i = 0; i < row; i++)
			{
				ImGui::TableNextRow();
				for (int col = 0; col < mEvents.size(); col++)
				{
					ImGui::TableSetColumnIndex(col);
					std::vector<CodeTile*> currentTiles = mEvents[col]->GetTiles();
					if(currentTiles.size()!=0)
						if (ImGui::Button(i < currentTiles.size() ? currentTiles[i]->GetTileName().c_str() : ""))
						{
							bDetailsOpen = true;
							mTileDetails = std::bind(&CodeTile::RenderImGui, currentTiles[i]);
						}
				}
			}
			
			ImGui::EndTable();
		}
		ImGui::End();
	}
	void CodeHandler::EventHappened(Event& e)
	{
		EventDispatcher d(e);
		d.Dispatch<BeginPlay>(BIND_EVENT_FUNCTION(&CodeHandler::OnBeginPlay));
	}
	bool CodeHandler::OnBeginPlay(Event& e)
	{
		EventTile* bp = GetEventByName("Begin Play").get();
		if (bp)
		{
			bp->Execute(e);
		}
		return true;
	}
	int CodeHandler::GetMostInstruction()
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
	std::shared_ptr<EventTile> CodeHandler::GetEventByName(const std::string& name)
	{
		for (auto event : mEvents)
		{
			if (event->GetName() == name)
			{
				return event;
			}
		}
	}
}