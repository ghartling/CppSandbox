// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "gtest/gtest.h"
#include "json.hpp"

// for convenience
using json = nlohmann::json;

namespace JsonTestSuite {

// Step 2. Use the TEST macro to define your tests.
//
// TEST has two parameters: the test case name and the test name.

// Tests factorial of 0.
TEST(JsonTest, testParse) {
	// parse explicitly
	auto j = json::parse("{ \"happy\": true, \"pi\": 3.141 }");

	// explicit conversion to string
	std::string s = j.dump();    // {\"happy\":true,\"pi\":3.141}

	// serialization with pretty printing
	// pass in the amount of spaces to indent
	std::cout << j.dump(4) << std::endl;
	EXPECT_TRUE(s.length()>0);
}

}

