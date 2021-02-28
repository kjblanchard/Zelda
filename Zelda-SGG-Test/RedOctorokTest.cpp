#include "pch.h"
#include "CppUnitTest.h"

#include "characters/RedOctorok.h"

#include "../Zelda-SGG/src/characters/RedOctorok.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ZeldaSGGTest
{
	TEST_CLASS(RedOctorokTest)
	{
	public:

		TEST_METHOD(InstantiationTest)
		{
			auto location = SG::Vector3(0);
			auto octo = new RedOctorok();
			Assert::AreEqual(location.X, octo->Location().X);
		}

		TEST_METHOD(SGGTEST)
		{
			auto loc = SG::Vector3(25, 25);
			auto Oktorok = new RedOctorok(loc);
			Assert::AreEqual(loc.X, Oktorok->Location().X);
		}
	};
}