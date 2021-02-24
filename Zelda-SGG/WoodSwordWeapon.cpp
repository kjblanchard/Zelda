#include "WoodSwordWeapon.h"

#include "Statics.h"
#include "components/ImageComponent.h"
#include "components/BoxColliderComponent.h"
#include "Image.h"
#include "data/Directions.h"


WoodSwordWeapon::WoodSwordWeapon(SG::Vector3 location, GameObject* owner, SG::GameObjectTypes gameObjectType) : Weapon(location,owner,gameObjectType)
{
}

void WoodSwordWeapon::Startup()
{


	const auto currentDirection = Owner->GetDirection();
	const auto swordSpriteLocAndOffset = ReturnSwordOffsets(currentDirection);
	const auto swordCompOffset = ReturnSwordColliderOffsets(currentDirection);
	
	ImageComp = new SG::ImageComponent(SG::SpriteSheetEnum::WoodSword, SDL_Rect{ swordSpriteLocAndOffset.first.X,swordSpriteLocAndOffset.first.Y, 32, 32 }, this);
	ImageComp->image->LocationAndSizeOnRenderer = SDL_Rect{ Location().X + swordSpriteLocAndOffset.second.X,Location().Y + swordSpriteLocAndOffset.second.Y,32,32 };
	auto boxColliderBox = SDL_Rect{ swordCompOffset.first.X,swordCompOffset.first.Y,swordCompOffset.second.X,swordCompOffset.second.Y };
	BoxColliderComp = new SG::BoxColliderComponent(this, boxColliderBox);

	BoxColliderComp->Startup();
}

void WoodSwordWeapon::Update(const double& deltaTime)
{
	auto xyOffSetForSword = ReturnSwordOffsets(Owner->GetDirection());

	ImageComp->Update(deltaTime);
	auto newLocation = SG::Vector3(Location().X + xyOffSetForSword.second.X, Location().Y + xyOffSetForSword.second.Y);
	ImageComp->UpdateSpriteDestinationInWorld(newLocation);
	BoxColliderComp->Update(deltaTime);
}

void WoodSwordWeapon::Draw(SG::SpriteBatch& spriteBatch)
{
	ImageComp->Draw(spriteBatch);
	BoxColliderComp->Draw(spriteBatch);
}

void WoodSwordWeapon::Reset()
{
}
