#include "ZeldaWorld.h"

#include "DebugRoomLevel.h"

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