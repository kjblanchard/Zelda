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
	ImageComp = new SG::ImageComponent(SG::SpriteSheetEnum::WoodSword, SG::Point(swordSpriteSheetLocations[0]), this);
	ImageComp->image->ImageIsWholeTexture = false;
	ImageComp->image->Size = SG::Point(32, 32);
	auto currentDirection = SG::Directions::Down;
	auto xyOffSetForSword = SG::Point(0);
	if(Owner->GetDirection() == SG::Directions::Up)
	{
	ImageComp->image->LocationAndSizeInSpriteSheet = SDL_Rect{ swordSpriteSheetLocations[0].X,swordSpriteSheetLocations[0].Y, 32, 32 };
	ImageComp->image->LocationAndSizeOnRenderer = SDL_Rect{ Location().X,Location().Y +16,32,32 };
	auto boxColliderBox = SDL_Rect{ 0,-32,32,32 };
	BoxColliderComp = new SG::BoxColliderComponent(this, boxColliderBox);
	}
	else if (Owner->GetDirection() == SG::Directions::Down)
	{
		ImageComp->image->LocationAndSizeInSpriteSheet = SDL_Rect{ swordSpriteSheetLocations[0].X,swordSpriteSheetLocations[1].Y, 32, 32 };
		ImageComp->image->LocationAndSizeOnRenderer = SDL_Rect{ Location().X,Location().Y - 16,32,32 };
		auto boxColliderBox = SDL_Rect{ 0,-32,32,32 };
		BoxColliderComp = new SG::BoxColliderComponent(this, boxColliderBox);
	}
	else if (Owner->GetDirection() == SG::Directions::Left)
	{
		xyOffSetForSword = ReturnSwordOffsets(Owner->GetDirection());
		ImageComp->image->LocationAndSizeInSpriteSheet = SDL_Rect{ swordSpriteSheetLocations[0].X,swordSpriteSheetLocations[2].Y, 32, 32 };

		ImageComp->image->LocationAndSizeOnRenderer = SDL_Rect{ Location().X + xyOffSetForSword.X,Location().Y + xyOffSetForSword.Y,32,32 };
		auto boxColliderBox = SDL_Rect{ 0,xyOffSetForSword.Y*2,32,32 };
		BoxColliderComp = new SG::BoxColliderComponent(this, boxColliderBox);
	}
	else
	{
		xyOffSetForSword = ReturnSwordOffsets(Owner->GetDirection());
		ImageComp->image->LocationAndSizeInSpriteSheet = SDL_Rect{ swordSpriteSheetLocations[0].X,swordSpriteSheetLocations[3].Y, 32, 32 };
		ImageComp->image->LocationAndSizeOnRenderer = SDL_Rect{ Location().X + xyOffSetForSword.X,Location().Y + xyOffSetForSword.Y,32,32 };
		auto boxColliderBox = SDL_Rect{ xyOffSetForSword.X,xyOffSetForSword.Y,16,16 };
		BoxColliderComp = new SG::BoxColliderComponent(this, boxColliderBox);
	}

	//ImageComp->UpdateSpriteDestinationInWorld(Location());


}

void WoodSwordWeapon::Update(const double& deltaTime)
{
	auto xyOffSetForSword = ReturnSwordOffsets(Owner->GetDirection());

	ImageComp->Update(deltaTime);
	auto newLocation = SG::Vector3(Location().X + xyOffSetForSword.X, Location().Y + xyOffSetForSword.Y);
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
