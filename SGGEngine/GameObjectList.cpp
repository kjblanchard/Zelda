#include "pch.h"
#include  "GameObjectList.h"

namespace SG
{
	void GameObjectList::Startup()
	{
	}

	void GameObjectList::Update(const double& deltaTime)
	{
		GameObjectStartup();
		for (auto* gameObject : _gameObjectList)
		{
			gameObject->Update(deltaTime);
		}
	}

	void GameObjectList::Draw(SpriteBatch& spriteBatch)
	{
		for (auto* gameObject : _gameObjectList)
		{
			gameObject->Draw(spriteBatch);
		}
	}

	void GameObjectList::Reset()
	{
		for (auto* gameObject : _gameObjectList)
		{
			delete gameObject;
		}
		_gameObjectList.clear();

		for (auto* gameObject : _gameObjectStartupList)
		{
			delete gameObject;
		}
		_gameObjectList.clear();
	}

	void GameObjectList::AddToGameObjectList(GameObject* gameObject)
	{
		_gameObjectStartupList.push_back((gameObject));

	}

	void GameObjectList::GameObjectStartup()
	{
		if (!_gameObjectStartupList.empty())
		{
			for (auto* gameObject : _gameObjectStartupList)
			{
				gameObject->Startup();
				_gameObjectList.push_back(gameObject);

			}
		_gameObjectStartupList.clear();

		}

	}
}
