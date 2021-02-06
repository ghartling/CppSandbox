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

namespace datetest
{
	TEST_CLASS(DateTimeUnitTest) {
public:


	/**
	* Get the time difference between two times in milliseconds
	*/
	TEST_METHOD(testDurationMilliseconds) {
		const std::chrono::time_point<std::chrono::system_clock> p1 = std::chrono::system_clock::now();
		const std::chrono::time_point<std::chrono::system_clock> p2 = p1 - std::chrono::milliseconds(101);

		long diff = getDurationMillis(p2);
		
		writeMessage("milliseconds: ", diff);

		// test uninitialized date
		const std::chrono::time_point<std::chrono::system_clock> timeUninitialized;
		diff = getDurationMillis(timeUninitialized);
		writeMessage("milliseconds timeUninitialized: ", diff);
	}

	/**
	* Get the time difference between a time in the past and the current time in milliseconds
	*/
	long getDurationMillis(const std::chrono::time_point<std::chrono::system_clock> t1) {
		const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

		long t1Millis = std::chrono::duration_cast<std::chrono::milliseconds>(t1.time_since_epoch()).count();
		long nowMillis = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

		return nowMillis - t1Millis;
	}

	TEST_METHOD(testStdTime) {
		std::chrono::time_point<std::chrono::system_clock> now =
			std::chrono::system_clock::now();
		auto duration = now.time_since_epoch();
		long millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

		time_t nowt = time(NULL);
		long totalSec = nowt;

		char logmsg[256];
		sprintf_s(logmsg, "milliseconds since epoch: %d", millis);
		Logger::WriteMessage(logmsg);
		sprintf_s(logmsg, "seconds:      %d", totalSec);
		Logger::WriteMessage(logmsg);
		long l = duration.count();
		sprintf_s(logmsg, "duration:     %d", l);
		Logger::WriteMessage(logmsg);

		// format local time
		std::tm localTime = *localtime(&nowt);

		sprintf_s(logmsg, "formatted time: %s", std::asctime(&localTime));
		Logger::WriteMessage(logmsg);
	}

	TEST_METHOD(testTimeTotalSeconds) {
		char text[100] = {};
		time_t now = time(NULL);
		long totalSec = now ;

		std::string hhmm = formatTime(totalSec);
		writeMessage("HH:MM ", hhmm.c_str());

		long secPerDay = (3600 * 24);
		long secPerHour = 3600;

		long days = totalSec / secPerDay;
		totalSec = totalSec - days * secPerDay;

		long hours = totalSec / secPerHour;
		totalSec = totalSec - hours * secPerHour;

		long min = totalSec / 60;

		sprintf_s(text, "%02i:%02i, total = %d, now = %d", hours, min, totalSec, now);
		writeMessage("HH:MM ", text);
	}

	TEST_METHOD(testDurationSeconds) {
		char text[100] = {};
//		time_t now = time(NULL);
		long totalSec = 45000;

		std::string hhmm = formatTimeDaySeconds(totalSec);
		writeMessage("HH:MM ", hhmm.c_str());

		long secPerDay = (3600 * 24);
		long secPerHour = 3600;

		long days = totalSec / secPerDay;
		totalSec = totalSec - days * secPerDay;

		long hours = totalSec / secPerHour;
		totalSec = totalSec - hours * secPerHour;

		long min = totalSec / 60;

		sprintf_s(text, "%02i:%02i, total = %i", hours, min, totalSec);
		writeMessage("HH:MM ", text);
	}

	TEST_METHOD(testTimer) {
		char text[100] = {};
		time_t now = time(NULL);
		long totalSec = now;

		std::string hhmm = formatTime(totalSec);
		writeMessage("HH:MM ", hhmm.c_str());

		long secPerDay = (3600 * 24);
		long secPerHour = 3600;

		long days = totalSec / secPerDay;
		totalSec = totalSec - days * secPerDay;

		long hours = totalSec / secPerHour;
		totalSec = totalSec - hours * secPerHour;

		long min = totalSec / 60;

		sprintf_s(text, "%02i:%02i, total = %d, now = %d", hours, min, totalSec, now);
		writeMessage("HH:MM ", text);
	}

	std::string formatTimeDaySeconds(long totalTimeInSec) {
		long totalSec = totalTimeInSec;

		long secPerHour = 3600;

		long hours = totalSec / secPerHour;
		totalSec = totalSec - hours * secPerHour;

		long min = totalSec / 60;

		char text[100] = {};
		sprintf_s(text, "%02i:%02i, total = %i, totalTimeInSec = %i", hours, min, totalSec, totalTimeInSec);
		writeMessage("HH:MM ", text);

		char hhmm[100] = {};
		sprintf_s(hhmm, "%02i:%02i", hours, min);

		return hhmm;
	}

	std::string formatTime(long totalTimeInSec) {
		long totalSec = totalTimeInSec;

		long secPerDay = (3600 * 24);
		long secPerHour = 3600;

		long days = totalSec / secPerDay;
		totalSec = totalSec - days * secPerDay;

		long hours = totalSec / secPerHour;
		totalSec = totalSec - hours * secPerHour;

		long min = totalSec / 60;

		char text[100] = {};
		sprintf_s(text, "%02i:%02i, total = %i, totalTimeInSec = %i", hours, min, totalSec, totalTimeInSec);
		writeMessage("HH:MM ", text);

		char hhmm[100] = {};
		sprintf_s(hhmm, "%02i:%02i", hours, min);

		return hhmm;
	}

	void writeMessage(char* msg, const char* val) {
		char logmsg[256] = {};
		sprintf_s(logmsg, "%s: %4s", msg, val);
		Logger::WriteMessage(logmsg);
	}

	void writeMessage(char* msg, long val) {
		char logmsg[256] = {};
		sprintf_s(logmsg, "%s: %d", msg, val);
		Logger::WriteMessage(logmsg);

	}

	};
}
