#include "ZeldaLevel.h"
#include "ZeldaWorld.h"
#include "levels/DebugRoomLevel.h"

void ZeldaLevel::AddAllGameLevels()
{
	LevelStateMachine.AddStateToGameStateList(ZeldaLevels::DebugRoom,  std::make_unique<DebugRoomLevel>());
}


