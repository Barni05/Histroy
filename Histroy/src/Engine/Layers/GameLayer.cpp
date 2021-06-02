#include "hspch.h"
#include "GameLayer.h"
namespace Histroy
{
    GameLayer::GameLayer()
    {
		mGameViewportDetails.height = 1080;
		mGameViewportDetails.width = 1000;
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
	void GameLayer::PlayGame()
	{
		std::thread t(Start, this);
		t.detach();
	}
	void GameLayer::Start(GameLayer* layer)
	{
		layer->mGameViewport = new Window({ "Game Viewport", layer->mGameViewportDetails.width, layer->mGameViewportDetails.height });
		layer->mGameViewport->SetCallback(&Application::OnEventHappened);
		layer->mGameViewport->Init(nullptr, nullptr);
		layer->mGameViewport->MakeContextCurrent();
		Window::InitGlew();
		BeginPlay bp(layer->mGameViewport);

		for (auto actor : Application::sGeometries)
		{
			layer->mActors.push_back(actor->clone());
		}
		layer->sProgram.BeginPlay(bp);
		while (!glfwWindowShouldClose(layer->mGameViewport->GetWindow()))
		{

			layer->mGameViewport->MakeContextCurrent();

			HistroyRenderer::Render(layer->mActors);

			//TODO: bug here, variables are 0
			layer->mGameViewport->Update(layer->mGameViewportDetails.x, layer->mGameViewportDetails.y, layer->mGameViewportDetails.viewportWidth, layer->mGameViewportDetails.viewportHeight);

			glfwPollEvents();
			glClear(GL_COLOR_BUFFER_BIT);

		}
	}
}