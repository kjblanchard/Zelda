////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#ifdef SGGENGINE_EXPORTS
#define SGGENGINE_API __declspec(dllexport)
#else
#define SGGENGINE_API __declspec(dllimport)
#endif
#include <SDL_rect.h>
#include <functional>
#include "core/GameObject.h"
#include "components/Component.h"
#include "interfaces/IUpdate.h"

namespace SG
{
	class GameLevel;
	class SpriteBatch;
	/// <summary>
	/// Component used for collision detection
	/// </summary>
	class SGGENGINE_API BoxColliderComponent : public Component
	{
	public:

		/// <summary>
		/// Component used for collision detection
		/// </summary>
		/// <param name="_gameObject">The owner of this component</param>
		/// <param name="offsetAndSize">The xy offset of the colliderto its owner, and the size of the collider</param>
		/// <param name="debugMode">Should a debug box be drawn</param>
		BoxColliderComponent(GameObject* _gameObject, SDL_Rect offsetAndSize, bool debugMode = false);

		void Startup() override;
		void Update(const double& deltaTime) override;
		void Draw(SpriteBatch& spriteBatch) override;

		/// <summary>
		/// Called by the gamelevel most likely, takes in a collider and returns if it intersects with this object
		/// </summary>
		/// <param name="otherCollider">The collider to check against itself</param>
		/// <returns>Returns true if there is a collision, false otherwise</returns>
		bool IsCollision(const SDL_Rect& otherCollider) const;

		/// <summary>
		/// Checks against a layer in a game level, and adds the current frames collisions with those objects
		/// </summary>
		/// <param name="gameLevelToCheck">The current gameLevel to check against</param>
		/// <param name="typeToCheckAgainst">An enum of the layer of gameobjects to check against</param>
		void GatherAllCurrentIntersections(SG::GameLevel* gameLevelToCheck,  SG::GameObjectTypes typeToCheckAgainst);

		/// <summary>
		/// Calls the passed in function on each item in the current collisions, if it was just intersected against
		/// </summary>
		/// <param name="functionToCallOnEach">A function to be called when an overlap happens, must be a void return with no arguments</param>
		void CallFunctionOnEachJustIntersected(std::function<void()> functionToCallOnEach);

		/// <summary>
		/// Sets the variable that controls drawing of the debug box
		/// </summary>
		/// <param name="shouldDraw">True will draw the debug box every frame around the box collider rect</param>
		void SetShouldDrawDebugBox(const bool shouldDraw)
		{
			_shouldDrawDebugBox = shouldDraw;
		};

		/// <summary>
		/// Gets a const reference of the current collider box
		/// </summary>
		/// <returns>Reference to The current rectangle of the collider box</returns>
		const SDL_Rect& ColliderBox() const
		{
			return _colliderBox;
		}

	private:
		/// <summary>
		/// Used by the call function on each intersected function.  Compares the current and previous frame collisions of a current object ID and this one
		/// </summary>
		/// <param name="gameObjectId">The ID that will be checked against</param>
		/// <returns>True if the collider with the ID is in the current frame and not previous frame</returns>
		bool CheckIfJustIntersected(int gameObjectId);
		SDL_Rect _colliderBox;
		bool _shouldDrawDebugBox = false;
		int _xOffset = 0;
		int _yOffset = 0;
		int _xSizeOffset = 0;
		int _ySizeOffset = 0;

		std::vector<GameObject*> _currentFrameCollisions = {};
		std::vector<GameObject*> _previousFrameCollisions = {};




	};
}
