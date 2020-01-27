#include "pch.h"
#include "CppUnitTest.h"
#include <vector>


using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NumberTest
{
	TEST_CLASS(NumberTest) {
public:

	TEST_METHOD(floatTest) {
		float x = 12345.6;
		char buf[32];
		sprintf_s(buf, "port: %5.1f", x);

		Logger::WriteMessage(buf);
		
	}

	TEST_METHOD(iTest) {
		int num = 5;
		char temp[32] = {};
		sprintf_s(temp, "%02i", num);

		Logger::WriteMessage(temp);

	}

	};
}
