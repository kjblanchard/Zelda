#include "Application.h"
#include "Game.h"

int main()
{
	auto* app = new Application();
	app->InitializeGame();
	return 1;
}

void Application::InitializeGame()
{
	_game = std::make_unique<SG::Game>();
	_game->Loop();
}