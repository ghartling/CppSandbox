/*
 * AllTests.cpp
 *
 *  Created on: Feb 19, 2020
 *      Author: Gerald.Hartling
 */

#include "gtest/gtest.h"
//#include "FooTests.cpp"

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}




