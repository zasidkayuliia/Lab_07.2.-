#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.2.it/Lab_07.2.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

			int rows = 0;
			int cols = 0;
			int** a = nullptr; 

			int sum = SumMaxOddColumns(a, rows, cols);

			Assert::AreEqual(0, sum);
		}
		

	};
}
	