#include "ZeldaWorld.h"

#include "DebugRoomLevel.h"

void ZeldaWorld::Update(const double& deltaTime)
{
	_levelStateMachine.Update(deltaTime);
}

void ZeldaWorld::Startup()
{
	_levelStateMachine.AddStateToGameStateList(ZeldaLevels::DebugRoom, std::make_unique<DebugRoomLevel>());
	_levelStateMachine.ChangeState(ZeldaLevels::DebugRoom);
}
