// Clock.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Clock
{
public:
	int hours;
	int minutes;
	int seconds;

	Clock() 
	{
		hours = 1;
		minutes = 0;
		seconds = 0;
	}

	Clock(int hour, int minute, int second) {
		if (hour > 24 || hour < 1 || minute > 60 || minute < 0 || second > 60 || second < 0) {
			cout << "Invalid Time" << endl;
			Clock();
			return;
		}

		hours = hour;
		minutes = minute;
		seconds = second;
	}

	void incSeconds() {
		if (seconds == 59) {
			seconds = 0;
			incMinutes();
			return;
		}
		seconds++;
		return;
	}

	void incMinutes() {
		if (minutes == 59) {
			minutes = 0;
			incHours();
			return;
		}
		minutes++;
		return;
	}

	void incHours() {
		if (hours == 24) {
			hours = 1;
			return;
		}
		hours++;
		return;
	}

	void printClock() {
		cout << hours << " : " << minutes << " : " << seconds << endl;
		return;
	}
};

class TwelveHourClock {
public:
	bool AM;
	int hours;
	int minutes;
	int seconds;

	TwelveHourClock() {
		AM = true;
		hours = 1;
		minutes = 0;
		seconds = 0;
	}

	TwelveHourClock(int hour, int minute, int second, bool AM_instance) {
		if (hour > 24 || hour < 1 || minute > 60 || minute < 0 || second > 60 || second < 0) {
			cout << "Invalid Time" << endl;
			TwelveHourClock();
			return;
		}

		AM = AM_instance;
		hours = hour;
		minutes = minute;
		seconds = second;
	}

	void incSeconds() {
		if (seconds == 59) {
			seconds = 0;
			incMinutes();
			return;
		}
		seconds++;
		return;
	}

	void incMinutes() {
		if (minutes == 59) {
			minutes = 0;
			incHours();
			return;
		}
		minutes++;
		return;
	}

	void incHours() {
		if (hours == 11) {
			hours++;
			
			if (AM) {
				AM = false;
			}
			else {
				AM = true;
			}
			return;
		}

		if (hours == 12) {
			hours = 1;
			return;
		}

		hours++;
		return;

	}

	void printClock() {
		cout << hours << " : " << minutes << " : " << seconds << "	";
		if (AM) {
			cout << "A.M." << endl;
		}
		else {
			cout << "P.M." << endl;
		}
		return;
	}


};


int main()
{
	Clock clock1;
	int counter = 0;
	/*while (counter <= ((3600 * 49))/60 )  {
		clock1.printClock();
		clock1.incSeconds();
		counter++;
	}*/

	cout << endl << "------------------------------" << endl << "12 hour clock:" << endl;
	counter = 0;
	

	TwelveHourClock clock2(3,0,0,false);
	while (counter <= (3600) * 15) {
		clock2.printClock();
		clock2.incSeconds();
		counter++;
	}

	int t;
	cin >> t;

    return 0;
}

