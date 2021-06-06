#pragma once
namespace Histroy
{
	class GameLayer
	{
	public:
		GameLayer();
		~GameLayer();

		void UpdateViewport();
		void UpdateCodeTiles();
		void PlayGame();
		void CopyActors();

		static void Start(GameLayer* layer);

		WindowDetails mGameViewportDetails;
	private:
		Window* mGameViewport;
		Program mProgram;

		std::vector<Geometry*> mActors;
	};
}
