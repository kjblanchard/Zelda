#include "Application.h"
#include "Game.h"
#include "GameObject.h"
#include "Player.h"
#include "SpriteBatch.h"

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

	auto* player = new Player();
	player->Startup();

	auto* spriteBatch = new SG::SpriteBatch();
	player->Draw( *spriteBatch);

	SG::Game::GetGraphics()->Draw(*spriteBatch);




}