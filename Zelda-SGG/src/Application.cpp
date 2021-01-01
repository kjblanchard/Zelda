#include "Application.h"
#include "Game.h"
#include "GameObject.h"
#include "Graphics.h"
#include "SpriteBatch.h"
#include "Player.h"


int main(int argc, char* args[])
{
	auto* app = new Application();
	app->InitializeGame();
	return 1;
}

void Application::InitializeGame()
{
	_game = std::make_unique<SG::Game>();
	_game->Startup();
	_game->Loop();

}