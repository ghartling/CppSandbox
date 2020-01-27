#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			cout << "test" << endl;
			// TODO: Your test code here
		}

	};
}