#pragma once
namespace Histroy
{
	class GameLayer
	{
	public:
		GameLayer();
		~GameLayer();

		void UpdateViewport();
		void PlayGame();

		static void Start(GameLayer* layer);

		WindowDetails mGameViewportDetails;
	private:
		Window* mGameViewport;
		Program sProgram;

		std::vector<Geometry*> mActors;
	};
}
