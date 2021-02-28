#include "ZeldaWorld.h"
#include "core/GameObjectList.h"
#include "graphics/SpriteBatch.h"
#include "graphics/Graphics.h"
#include "Statics.h"
#include "ZeldaLevel.h"
#include "core/Configuration.h"


int main(int argc, char* args[])
{
	auto zeldaWorld = std::make_unique<ZeldaWorld>();
	SG::Configuration::GenerateJsonFromConfigFile("appsettings.json");
	if (!SG::Configuration::GenerateValuesFromJson())
		return 1;
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
