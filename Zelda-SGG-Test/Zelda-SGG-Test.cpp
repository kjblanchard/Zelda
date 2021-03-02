#include "pch.h"
#include "CppUnitTest.h"
#include "data/Vector3.h"




using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ZeldaSGGTest
{
	TEST_CLASS(ZeldaSGGTest)
	{
	public:

		TEST_METHOD(Vector3Test)
		{
			auto location = SG::Vector3(0);
			Assert::AreEqual(location.X, location.X);
		}
	};
}
