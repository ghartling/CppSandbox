#include "stdafx.h"
#include "CppUnitTest.h"

#include "Sandbox.h"
#include "Section11Challenge.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SandboxUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Sandbox s;
			int x=s.product(5, 4);

		
			Assert::AreEqual(20, x);
		}
		
		TEST_METHOD(TestMethod2)
		{
			Section11Challenge s11;
			s11.solution();

		
//			Assert::AreEqual(20, x);
		}

	};
}