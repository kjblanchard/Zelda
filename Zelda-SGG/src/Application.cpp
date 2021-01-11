#include "Application.h"
#include "Game.h"
#include "GameObject.h"
#include "Graphics.h"
#include "Player.h"
#include "SpriteBatch.h"
#include "Input.h"


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
	SG::Game::AddToGameObjectList(std::make_unique<Player>(SG::Vector3(32)));
	_game->Loop();

}