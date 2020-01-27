#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <array>
#include <WinSock2.h>


using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SandboxUnitTest2019
{
	TEST_CLASS(A320Test) {
public:
	int x[4] = { 1,2,3,4 };

	array<int, 3> xa { 10,20,30 };

	TEST_METHOD(TestByteSwap) {
		const int size = 16;
		char testStr[size]{};
		unsigned int one = 1;
		unsigned int Identifier = 0;

		const int test[3] = { 1,2,3 };

		for(int i=0; i<4; ++i) {
			testStr[i] = one;
		}

		// confirm that int is 4 bytes
		int sizeOfUnsigned = sizeof(int);
		Assert::AreEqual(sizeOfUnsigned, 4);

		// copy byte arry into int
		memcpy(&Identifier, testStr, sizeof(int));

		//     1         2         3         4
		// 000‭1 0000 0001 0000 0001 0000 0001‬
		unsigned int result = 1 + pow(2, 8) + pow(2, 16) + pow(2, 24);
		Assert::AreEqual(result, Identifier);
	}

	};
}
