#include "characters/RedOctorok.h"
#include <SDL_rect.h>
#include "components/BoxColliderComponent.h"
#include "components/AnimationComponent.h"


RedOctorok::RedOctorok(SG::Vector3 location) : GameObject(location,SG::GameObjectTypes::Enemy),_boxColliderComponent(nullptr)
{
	auto boxColliderBox = SDL_Rect{ 0,0,24,24 };
	_boxColliderComponent = std::make_unique<SG::BoxColliderComponent>(this, boxColliderBox, true);
}

void RedOctorok::Startup()
{
}

void RedOctorok::Update(const double& deltaTime)
{
}

void RedOctorok::Draw(SG::SpriteBatch& spriteBatch)
{
}
