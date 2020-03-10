#include "pch.h"
#include "CppUnitTest.h"
#include "../IntersectProject/line.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			extern map<pair<double, double>, int> points;
			line l1(0, 1, 0, 0);
			line l2(0, 0, 1, 1);
			line::calInteract(l1, l2);
			Assert::AreEqual((int)points.size(), 1);
		}
	};
}
