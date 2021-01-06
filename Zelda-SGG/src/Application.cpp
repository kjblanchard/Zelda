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
	auto* const player = new Player(SG::Vector3(32));
	player->Startup();
	_game->_gameObjectList.push_back(player);
	_game->Loop();

}