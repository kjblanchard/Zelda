#include "states/RedOctorok/RedOctorokMovingState.h"
#include "characters/RedOctorok.h"

RedOctorokMovingState::RedOctorokMovingState(RedOctorok* owner) : _redOctorok(owner)
{
}

void RedOctorokMovingState::Startup()
{
}

void RedOctorokMovingState::Update(const double& deltaTime)
{
	//_redOctorok->_location.Y -= 1;
}

void RedOctorokMovingState::Draw(SG::SpriteBatch& spriteBatch)
{
}

void RedOctorokMovingState::End()
{
}
