#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Win32Project/FavoriteNumber.h"
#include "../ConsoleApplication/ConsoleFavoriteNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			FavoriteNumber fav;
			// TODO: Your test code here
			fav.printFavoriteNumber();

//			ConsoleFavoriteNumber consoleFav;
//			consoleFav.printFavoriteNumber();
		}

	};
}