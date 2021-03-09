#include "ZeldaWorld.h"

#include "ZeldaConfig.h"
#include "core/GameObjectList.h"
#include "graphics/SpriteBatch.h"
#include "graphics/Graphics.h"
#include "ZeldaLevel.h"
#include "core/Configuration.h"


int main(int argc, char* args[])
{
	auto zeldaWorld = std::make_unique<ZeldaWorld>();
	if (!zeldaWorld->SetupWorldComponents())
		return 0;
	zeldaWorld->Loop();
	return 1;
}

ZeldaWorld::ZeldaWorld()
	:World()
{
}

void ZeldaWorld::Startup()
{
	ZeldaConfig::PopulateZeldaConfigStats();
	_zeldaLevel = std::make_unique<ZeldaLevel>();
	_zeldaLevel->Startup();
	_zeldaLevel->ChangeLevel(ZeldaLevels::DebugRoom);
	_isCollisionDebug = false;
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
