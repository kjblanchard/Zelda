#include "ZeldaWorld.h"
#include "GameObjectList.h"
#include "DebugRoomLevel.h"
#include "SpriteBatch.h"
#include "Graphics.h"

int main(int argc, char* args[])
{
	auto zeldaWorld = std::make_unique<ZeldaWorld>();
	zeldaWorld->SetupWorldComponents();
	zeldaWorld->Loop();
	return 1;
}

void ZeldaWorld::Startup()
{
	_levelStateMachine.AddStateToGameStateList(ZeldaLevels::DebugRoom, std::make_unique<DebugRoomLevel>());
	_levelStateMachine.ChangeState(ZeldaLevels::DebugRoom);
}

void ZeldaWorld::Update(const double& deltaTime)
{
	_levelStateMachine.Update(deltaTime);
}

void ZeldaWorld::Draw()
{
	auto spriteBatch = SG::SpriteBatch();
	_levelStateMachine.Draw(spriteBatch);
	_graphics->Draw(spriteBatch);

}
