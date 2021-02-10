#include "ZeldaLevel.h"
#include "ZeldaWorld.h"
#include "DebugRoomLevel.h"

void ZeldaLevel::AddAllGameLevels()
{
	LevelStateMachine.AddStateToGameStateList(ZeldaLevels::DebugRoom, std::make_unique<DebugRoomLevel>());
}


