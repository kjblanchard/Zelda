#pragma once
#ifdef SGGENGINE_EXPORTS
#define SGGENGINE_API __declspec(dllexport)
#else
#define SGGENGINE_API __declspec(dllimport)
#endif

namespace SG
{
	class SGGENGINE_API State
	{

	public:
		virtual ~State() = default;
		virtual void Startup() = 0;
		virtual void Update() = 0;
		virtual void End() = 0 ;

	protected:

	};

}
