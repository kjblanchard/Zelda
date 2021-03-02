#include "pch.h"
#include "CppUnitTest.h"
#include "animation/RedOctorokAnimations/RedOctorokAnimations.h"
#include "animation/RedOctorokAnimations/RedOctorokAnimationController.h"
#include "characters/RedOctorok.h"
#include "components/BoxColliderComponent.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ZeldaSGGTest
{
	TEST_CLASS(RedOctorokTest)
	{
	public:

		TEST_METHOD(LocationTest)
		{
			auto loc = SG::Vector3(25, 25);
			auto Oktorok = new RedOctorok(loc);
			Assert::AreEqual(loc.X, Oktorok->Location().X);
			Assert::AreEqual(loc.Y, Oktorok->Location().Y);
		}

		TEST_METHOD(BoxColliderTest)
		{
			auto boxColliderBox = SDL_Rect{ 0,0,30,30 };
			auto Oktorok = new RedOctorok(SG::Vector3());
			auto oktoBox = Oktorok->GetComponent<SG::BoxColliderComponent>();
			Assert::AreEqual( boxColliderBox.x,oktoBox->ColliderBox().x);
			Assert::AreEqual(boxColliderBox.y, oktoBox->ColliderBox().y);
			Assert::AreEqual(boxColliderBox.w, oktoBox->ColliderBox().w);
			Assert::AreEqual(boxColliderBox.h, oktoBox->ColliderBox().h);
			Oktorok->Startup();
		}
		TEST_METHOD(AnimationComponentTest)
		{
			auto boxColliderBox = SDL_Rect{ 0,0,30,30 };
			auto Oktorok = new RedOctorok(SG::Vector3());
			auto oktoBox = Oktorok->GetComponent(SG::SGComponentTypes::Animation);
			auto animComponent = (SG::AnimationComponent<RedOctorokAnimationController,RedOctorokAnimations>*)(oktoBox);
			Oktorok->Startup();
			if(animComponent)
				Assert::IsTrue(animComponent->IsAnimPlaying);
		}
	};
}