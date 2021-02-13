#include "ZeldaWorld.h"
#include "GameObjectList.h"
#include "DebugRoomLevel.h"
#include "SpriteBatch.h"
#include "Graphics.h"
#include "Statics.h"
#include "ZeldaLevel.h"


int main(int argc, char* args[])
{
	auto zeldaWorld = std::make_unique<ZeldaWorld>();
	zeldaWorld->SetupWorldComponents();
	zeldaWorld->Loop();
	return 1;
}

ZeldaWorld::ZeldaWorld()
	:World(SG::Point(Statics::ScreenWidth,Statics::ScreenHeight))
{
}

void ZeldaWorld::Startup()
{
	_zeldaLevel = std::make_unique<ZeldaLevel>();
	_zeldaLevel->Startup();
	_zeldaLevel->ChangeLevel(ZeldaLevels::DebugRoom);
}

void ZeldaWorld::Update(const double& deltaTime)
{
	_zeldaLevel->Update(deltaTime);
}

void ZeldaWorld::Draw()
{
	auto spriteBatch = SG::SpriteBatch();
	_zeldaLevel->Draw(spriteBatch);
	_graphics->Draw(spriteBatch);

}
