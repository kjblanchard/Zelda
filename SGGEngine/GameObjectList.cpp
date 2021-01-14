#include "pch.h"
#include  "GameObjectList.h"

namespace SG
{
	std::vector<std::unique_ptr<GameObject>> GameObjectList::_gameObjectList;
	std::vector<std::unique_ptr<GameObject>> GameObjectList::_gameObjectStartupList;

	void GameObjectList::Startup()
	{
	}

	void GameObjectList::Update(const double& deltaTime)
	{
	}

	void GameObjectList::Draw(SpriteBatch& spriteBatch)
	{
	}

	void GameObjectList::AddToGameObjectList(std::unique_ptr<GameObject> gameObject)
	{
		_gameObjectStartupList.push_back(std::move(gameObject));

	}

	void GameObjectList::GameObjectStartup()
	{
		if (!_gameObjectStartupList.empty())
		{
			for (auto&& gameObjectStartupList : _gameObjectStartupList)
			{
				gameObjectStartupList->Startup();

			}
			for (auto&& gameObject : _gameObjectStartupList)
			{
				_gameObjectList.push_back(std::move(gameObject));
			}
		}
		_gameObjectStartupList.clear();


	}
}
