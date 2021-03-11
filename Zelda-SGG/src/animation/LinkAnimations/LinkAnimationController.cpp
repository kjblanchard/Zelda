#include "animation/LinkAnimations/LinkAnimationController.h"
#include "graphics/Image.h"
#include "graphics/SpriteBatch.h"
#include "animation/LinkAnimations/LinkAttackingAnimation.h"
#include "animation/LinkAnimations/LinkWalkingAnimation.h"
#include "animation/LinkAnimations/LinkWalkingHitAnimation.h"
#include "components/ImageComponent.h"
#include "core/Configuration.h"
#include "characters/Link.h"


//statics
std::vector<SG::Animation<LinkAnimations>> SG::AnimationController<LinkAnimations>::Animations;


LinkAnimationController::LinkAnimationController(SG::GameObject* gameObject) : AnimationController(gameObject)
{
	if (!staticsInitialized)
	{
		Animations = {
			{LinkWalkUp() },
			{LinkWalkRight()},
			{LinkWalkDown()},
			{LinkWalkLeft()},
			{LinkAttackUp() },
			{LinkAttackRight()},
			{LinkAttackDown()},
			{LinkAttackLeft()},
			{LinkWalkHitUp()},
			{LinkWalkHitDown()},
			{LinkWalkHitLeft()},
			{LinkWalkHitRight()}

		};
		staticsInitialized = true;
	}
	_link = dynamic_cast<Link*>(gameObject);
}

void LinkAnimationController::Startup()
{
	const auto sdlRect = SDL_Rect{ 0,0,  SG::Configuration::BaseConfigurationSettings.TileWidth, SG::Configuration::BaseConfigurationSettings.TileWidth};
	_imageComponent = new SG::ImageComponent( sdlRect, _gameObject);

	_imageComponent->image->ImageIsWholeTexture = false;
	AnimationController::Startup();
}

void LinkAnimationController::Update(const double& deltaTime)
{
	if(_link->_isMoving)
		AnimationController::Update(deltaTime);
	if(_link->_isInvincible)
	{
		currentInvincibilityFrame++;
		if (currentInvincibilityFrame > maxInvFrame)
			currentInvincibilityFrame = 0;
		UpdateSpriteLocation(_gameObject->Location());
	}

}

void LinkAnimationController::Draw(SG::SpriteBatch& spriteBatch)
{
	//TODO should I fix this for link and the redocto?  Same with the update, seems repetitive
	if(_link->_isInvincible)
	{
		auto currentFrameInInvincibility = CalculateCurrentFrameInInvincibility();
		auto coolBoi = _currentAnimation->DrawLocation(_currentFrameOnThisSprite);
		coolBoi.Y += currentFrameInInvincibility * invFrameOffset;
		_imageComponent->UpdateSpriteSheetLocation(coolBoi);
		_imageComponent->Draw(spriteBatch);

	}
	else
	{
	_imageComponent->UpdateSpriteSheetLocation(_currentAnimation->DrawLocation(_currentFrameOnThisSprite)); //this was one of the two only things here, besides draw
	_imageComponent->Draw(spriteBatch);

	}
}
