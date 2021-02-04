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
#include <vector>


#include "components/Component.h"
#include "data/Vector3.h"


namespace SG
{
	class SpriteBatch;
	struct Component;

	class SGGENGINE_API GameObject
	{
	public:
		GameObject();
		GameObject(Vector3 location);
		virtual ~GameObject() = default;
		/**
		 * \brief This function is called ONCE when the object is first instantiated, this happens after the constructor and should contain the heavy lifting not needed in the Constructor
		 */
		virtual void Startup();
		/**
		 * \brief This is to be called by the game loop once per frame.
		 */
		virtual void Update(const double& deltaTime);

		virtual void Draw(SpriteBatch& spriteBatch );

		virtual void Reset();

		bool ShouldUpdate() const;

		template <typename T >
		T* GetComponent();

		void AddComponent(Component* component);

		/**
		 * \brief Returns the location of the gameobject.
		 * \return Returns the location in a vector3.  Z is used in the draw order
		 */
		Vector3 Location() const;

	protected:

		Vector3 _location;
		bool _shouldUpdate = true;
		virtual void ComponentUpdate(const double& deltaTime);
		std::vector<Component*> _components;
	};

	template <typename T>
	T* GameObject::GetComponent()
	{
		for (auto*  component : _components)
		{
			auto result = dynamic_cast<T*> (component);
			if (result)
				return result;
		}
		return nullptr;
	}

}
