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

namespace SG
{
	class SpriteBatch;

	class SGGENGINE_API IUpdate
	{
	public:
		virtual ~IUpdate() = default;
	private:
		virtual void Startup()
		{

		}

		virtual void Update(const double& deltaTime)
		{
		}

		virtual void Draw(SpriteBatch& spriteBatch)
		{
		}
	};
}
