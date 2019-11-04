/* ----------- (c) Copyright 2019 L3 Technologies Inc --------------------
@DS --
Author		: G. Hartling, CESI
Description	:
@DE --
-------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------
Local Includes
---------------------------------------------------------------------------*/

#include <stdafx.h>
#include <math.h>
#include <time.h>

#include <iostream>
#include <chrono>
#include <string>
#include <mutex>

#include "VSConsoleLogger.h"

using namespace std::chrono;
using namespace std;

// define statics
CDelay VSConsoleLogger::loggingDelay;
char VSConsoleLogger::prefix[16] = {0};
InitVSConsoleLogger VSConsoleLogger::init;

static mutex mtx;


InitVSConsoleLogger::InitVSConsoleLogger() {
		// initialize the timer
		VSConsoleLogger::initLoggingIntervalOnStartup();
}

void VSConsoleLogger::info(char* msg) {
	lock_guard<mutex> lck(mtx);

	bool loggingState = loggingDelay.GetState();

	// if the delay has elapsed then log the statement and re-start the delay
	if (!loggingState) {

		// restart delay
		loggingDelay.Proc(1);

		// write the Visual Studio output window
		OutputDebugString(buildMessage(msg).data());
	}
	else {
		loggingDelay.Proc(0);
	}
}

void VSConsoleLogger::infoNoDelay(char* msg) {
	lock_guard<mutex> lck(mtx);

	// write the Visual Studio output window
	OutputDebugString(buildMessage(msg).data());
}

string VSConsoleLogger::buildMessage(char* msg) {

	string timestamp = buildTimestamp();
	char c[256];
	memset(&c, 0, sizeof(c));
	sprintf(c, "%s, %s, %s\n", timestamp.data(), prefix, (msg == nullptr ? " " : msg));

	return c;
}

string VSConsoleLogger::buildTimestamp() {
	time_t     now = time(0);
	struct tm  tstruct;
	tstruct = *localtime(&now);
	char buf[80];

	memset(&buf, 0, sizeof(buf));
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

void VSConsoleLogger::setPrefix(char* p) {
	lock_guard<mutex> lck(mtx);

	memset(&prefix, 0, sizeof(prefix));
	strncpy(prefix, p, sizeof(prefix));
}

void VSConsoleLogger::initLoggingIntervalOnStartup() {
	// initialize the timer
	loggingDelay.Init(0.0f, LOGGING_INTERVAL, (float)RTX_TIME_STEP);
}

void VSConsoleLogger::initLoggingInterval() {
	lock_guard<mutex> lck(mtx);

	// initialize the timer
	loggingDelay.Init(0.0f, LOGGING_INTERVAL, (float)RTX_TIME_STEP);
}

