/*
 * ThreadMain.cpp
 *
 *  Created on: Jun 6, 2020
 *      Author: ghartling
 */
#include <iostream>
#include <thread>
#include <cstdlib>

#include <unistd.h>

using namespace std;

void foo() {
	int i = 0;

	// time to sleep in microseconds
	int sleepTime = 1000000 * 1;
	while (true) {

		cout << "test foo thread iteration: " << i << endl;
		usleep(sleepTime);
		++i;
	}
}

void bar(int x) {
	int i = 0;

	// time to sleep in microseconds
	int sleepTime = 1000000 * 3;
	while (true) {

		cout << "test bar thread " << x << ", iteration: " << i << endl;
		usleep(sleepTime);
		++i;
	}

}

int main() {
	thread first(foo);
	thread second(bar, 7);
	first.join();
	second.join();
}

