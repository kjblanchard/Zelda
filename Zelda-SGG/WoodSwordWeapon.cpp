#include "WoodSwordWeapon.h"

#include "Statics.h"
#include "components/ImageComponent.h"
#include "components/BoxColliderComponent.h"
#include "Image.h"



WoodSwordWeapon::WoodSwordWeapon(SG::Vector3 location, GameObject* owner, SG::GameObjectTypes gameObjectType) : Weapon(location,owner,gameObjectType)
{
}

void WoodSwordWeapon::Startup()
{
	ImageComp = new SG::ImageComponent(SG::SpriteSheetEnum::WoodSword, SG::Point(swordSpriteSheetLocations[0]), this);
	ImageComp->image->ImageIsWholeTexture = false;
	ImageComp->image->Size = SG::Point(32, 32);
	ImageComp->image->LocationAndSizeInSpriteSheet = SDL_Rect{ swordSpriteSheetLocations[0].X,swordSpriteSheetLocations[0].Y, 32, 32 };
	ImageComp->image->LocationAndSizeOnRenderer = SDL_Rect{ Location().X,Location().Y +16,32,32 };
	//ImageComp->UpdateSpriteDestinationInWorld(Location());

	auto boxColliderBox = SDL_Rect{ 0,-32,32,32 };
	BoxColliderComp = new SG::BoxColliderComponent(this, boxColliderBox);

}

void WoodSwordWeapon::Update(const double& deltaTime)
{
	ImageComp->Update(deltaTime);
	auto newLocation = SG::Vector3(Location().X, Location().Y + 16);
	ImageComp->UpdateSpriteDestinationInWorld(newLocation);
	BoxColliderComp->Update(deltaTime);
}

void WoodSwordWeapon::Draw(SG::SpriteBatch& spriteBatch)
{
	ImageComp->Draw(spriteBatch);
	//BoxColliderComp->Draw(spriteBatch);
}

void WoodSwordWeapon::Reset()
{
}
