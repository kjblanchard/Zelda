#include "pch.h"
#define private public
#include "CppUnitTest.h"

#include "characters/RedOctorok.h"


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

	};
}