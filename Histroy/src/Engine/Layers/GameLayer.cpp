#include "hspch.h"
#include "GameLayer.h"
namespace Histroy
{
    GameLayer::GameLayer()
    {
		mGameViewportDetails.height = 1080;
		mGameViewportDetails.width = 1000;
		mGameViewportDetails.x = 0;
		mGameViewportDetails.y = 0;

		mGameViewport = new Window({ "Game Viewport", mGameViewportDetails.width, mGameViewportDetails.height });
    }
	GameLayer::~GameLayer()
	{
	}
	void GameLayer::UpdateViewport()
	{
		mGameViewportDetails.viewportHeight = mGameViewportDetails.height;
		mGameViewportDetails.viewportWidth = mGameViewportDetails.width;
		mGameViewportDetails.x = 0;
		mGameViewportDetails.y = 0;
	}
	void GameLayer::UpdateCodeTiles()
	{
		for (auto actor : mActors)
		{
			//actor->UpdateCode();
		}
	}
	void GameLayer::PlayGame()
	{
		std::thread t(Start, this);
		t.detach();
	}
	void GameLayer::CopyActors()
	{
		for (auto actor : Application::sGeometries)
		{
			mActors.push_back(actor->clone());
		}
		for (auto actor : mActors)
		{
			for (auto event : actor->GetCodeHandler()->GetEvents())
			{
				event->SetActor(actor);
			}
		}
	}
	void GameLayer::Start(GameLayer* layer)
	{
		layer->mActors.clear();
		layer->mGameViewport->SetCallback(&Application::OnEventHappened);
		layer->mGameViewport->Init(nullptr, nullptr);
		layer->mGameViewport->MakeContextCurrent();
		Window::InitGlew();

		layer->CopyActors();
		layer->mProgram.SetActors(layer->mActors);

		BeginPlay bp(layer->mGameViewport);
		layer->mProgram.BeginPlay(bp);
		std::cout << "MOveToTile:" << layer->mActors[0]->GetLocation().x << ";" << layer->mActors[0]->GetLocation().y << std::endl;

		while (!glfwWindowShouldClose(layer->mGameViewport->GetWindow()))
		{

			layer->mGameViewport->MakeContextCurrent();

			HistroyRenderer::Render(layer->mActors);

			layer->mGameViewport->Update(layer->mGameViewportDetails.x, layer->mGameViewportDetails.y, layer->mGameViewportDetails.viewportWidth, layer->mGameViewportDetails.viewportHeight);
			layer->UpdateViewport();
			glfwPollEvents();
			glClear(GL_COLOR_BUFFER_BIT);

		}
	}
}