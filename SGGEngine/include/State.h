#pragma once
#ifdef SGGENGINE_EXPORTS
#define SGGENGINE_API __declspec(dllexport)
#else
#define SGGENGINE_API __declspec(dllimport)
#endif

namespace SG
{
	class SpriteBatch;

	class SGGENGINE_API State
	{

	public:
		virtual ~State() = default;
		virtual void Startup() = 0;
		virtual void Update(const double& deltaTime) = 0;
		virtual void Draw(SpriteBatch& spriteBatch) = 0;
		virtual void End() = 0 ;

	protected:

	};

}
