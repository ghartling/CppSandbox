/* ----------- (c) Copyright 2019 L3 Technologies Inc - --------------
   @DS --
   File			: 
   Author		: G. Hartling, CESI
   Description	: 
   @DE --
   ------------------------------------------------------------------------ */

#ifndef VS_CONSOLE_LOGGER_INCLUDED
#define VS_CONSOLE_LOGGER_INCLUDED

#include <afc.h>
#include <string>

using namespace std;

/*START_SNAP*/
// number of seconds to wait between log statements
#define LOGGING_INTERVAL 1
/*STOP_SNAP*/

class InitVSConsoleLogger {
public:
	InitVSConsoleLogger();
};

/*START_SNAP*/
class VSConsoleLogger
{
private:

	static CDelay loggingDelay;
	static char prefix[16];

/*STOP_SNAP*/

	static string buildTimestamp();
	static string buildMessage(char*);

	~VSConsoleLogger() {
	}

	VSConsoleLogger() {
	}

public:

	static void initLoggingIntervalOnStartup();

    static void setPrefix(char *);
	static void initLoggingInterval();
	static void info(char *msg);
	static void infoNoDelay(char* msg);

    int Snap(void);

private:
	static InitVSConsoleLogger init;

/*START_SNAP*/
};
/*END_SNAP*/

#endif
