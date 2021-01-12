#include "Application.h"
#include "World.h"
#include "GameObject.h"
#include "Graphics.h"
#include "Player.h"
#include "SpriteBatch.h"
#include "Input.h"
#include "../ZeldaWorld.h"


int main(int argc, char* args[])
{
	auto* app = new Application();
	app->InitializeGame();
	return 1;
}

void Application::InitializeGame()
{
	_game = std::make_unique<ZeldaWorld>();
	_game->SetupWorldComponents();
	_game->Loop();

}