#include "pch.h"

#include "CppUnitTest.h"
#include <vector>
#include <iostream>
#include <map>
#include <cassert>
#include <array>
#include <unordered_map>
#include <time.h>
#include <ctime>
#include <chrono>
#include <iomanip>

//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace stringtest
{
	TEST_CLASS(StringUnitTest) {
public:

	TEST_METHOD(testCopyNull) {
		char c[] = { '\0' };
		copyNull("\0");
		copyNull(c);
	}

	TEST_METHOD(testInitStringWithCharArray) {
		char c[] = { "test" };
		std::string s = c;
		writeMessage("string ", s.c_str());

		writeMessage("string (c)", std::string(c).c_str());

	}

	TEST_METHOD(testAppendInt) {
		int i = 1;
		std::string s = "test" + std::to_string(i);
		writeMessage("string: ", s.c_str());
	}

	TEST_METHOD(testVectorOfString) {
		char c[] = { "test" };
		//vector<string> s = c;
		//writeMessage("string ", s.c_str());

		//writeMessage("string (c)", std::string(c).c_str());

	}
	TEST_METHOD(testInitCharArray) {
		char c[4][25];

		for (int i = 0; i < 4; ++i) {
			c[i][0] = {};
			writeMessage("string: ", c[i]);
		}
	}

	TEST_METHOD(testStrtok) {
		std::string str("Please split this sentence into tokens");
		char* next_token1 = NULL;

		char* cstr = new char[str.length() + 1];
		char msg[256] = {};
		sprintf_s(msg, "size: %4d", str.size());
		Logger::WriteMessage(msg);
		sprintf_s(msg, "length: %4d", str.length());
		Logger::WriteMessage(msg);
		//strcpy_s(cstr, str.size(), str.c_str());
		sprintf_s(msg, "%s", msg);

		// cstr now contains a c-string copy of str

		std::string space = " ";
		char* p = strtok_s(cstr, space.c_str(), &next_token1);
		while (p != 0) {
			std::cout << p << '\n';
			Logger::WriteMessage(p);
			p = strtok_s(NULL, " ", &next_token1);
		}

		delete[] cstr;
	}

	void copyNull(char str[]) {
		char c[5] = {};
		strcpy_s(c, "1234");
		Logger::WriteMessage(c);
		strcpy_s(c, str);

		char msg[256] = {};
		sprintf_s(msg, "after strcpy of 0: %4s", c);

		Logger::WriteMessage(msg);

	}

	void writeMessage(char* msg, const char* val) {
		char logmsg[256] = {};
		sprintf_s(logmsg, "%s: %4s", msg, val);
		Logger::WriteMessage(logmsg);
	}

	void writeMessage(char* msg, long val) {
		char logmsg[256] = {};
		sprintf_s(logmsg, "%s: %n", msg, val);
		Logger::WriteMessage(logmsg);

	}

	};
}
