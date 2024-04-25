/* Mitchell Gossman
   CS-210-R4728
   03/24/24 */

#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

// Global variables for the time with declared times for easier testing
int seconds = 59;
int minutes = 59;
int hours = 11;

// function to fill in zeros if numbers are not in a two digit format
string twoDigitString(int num) {
	ostringstream str;
	str << setw(2) << setfill('0') << num;
	return str.str();
}

// Function to fill in blank spaces and * for a better UI
string nCharString(int count, char s) {
	string output = "";
	
	for (int i = 0; i < count; ++i) {
		output = output + s;
	}
	return output;
}

// Takes the current time and determines when to roll down from 12 to 0 and determines AM or PM for the 12 hour format
string Get12_hour(int hours, int minutes, int seconds) {
	
	// temp variables for for am/pm and converting the hours when needed w/o changing the time
	string ampm = "";
	int temphours = 0;

	// Determines am/pm and when to roll down the hours - 12
	if (hours < 12) {
		temphours = hours;
		ampm = " AM";
	}
	else {
		temphours = hours - 12;
		ampm = " PM";
	}
	return twoDigitString(temphours) + ":" + twoDigitString(minutes) + ":" + twoDigitString(seconds) + ampm;
}

// Takes the current time and puts it into the 24 hour format
string Get24_hour(int hours, int minutes, int seconds) {
	
	return twoDigitString(hours) + ":" + twoDigitString(minutes) + ":" + twoDigitString(seconds);
}

// Displays the clock for 12 hour and 24 hour formats
void DisplayClock(int hours, int minutes, int seconds) {

	cout << nCharString(27, '*') + nCharString(3, ' ') + nCharString(27, '*') << endl;
	cout << nCharString(1, '*') + nCharString(6, ' ') + "12-HOUR CLOCK" + nCharString(6, ' ') + nCharString(1, '*') + "   ";
	cout << nCharString(1, '*') + nCharString(6, ' ') + "24-HOUR CLOCK" + nCharString(6, ' ') + nCharString(1, '*') << endl;
	cout << nCharString(1, '*') + nCharString(25, ' ') + nCharString(1, '*') + nCharString(3, ' ') + nCharString(1, '*') + nCharString(25, ' ') + nCharString(1, '*') << endl;
	cout << nCharString(1, '*') + nCharString(6, ' ') + Get12_hour(hours, minutes, seconds) + nCharString(8, ' ') + nCharString(1, '*') + nCharString(3, ' ');
	cout << nCharString(1, '*') + nCharString(8, ' ') + Get24_hour(hours, minutes, seconds) + nCharString(9, ' ') + nCharString(1, '*') << endl;
	cout << nCharString(27, '*') + nCharString(3, ' ') + nCharString(27, '*') << endl;
}

// Displays the menu options for the user and presents it cleanly
void DisplayMenu() {

	cout << "       Main Menu" << endl;
	cout << "*************************" << endl;
	cout << "* 1 - Add One Hour      *" << endl;
	cout << "* 2 - Add One Minute    *" << endl;
	cout << "* 3 - Add one Second    *" << endl;
	cout << "* 4 - Exit Program      *" << endl;
	cout << "*************************" << endl;
	cout << "Please select options 1 - 4" << endl;

}

// Adds 1 hour to time and rolls it back down to 0 if it goes to 24 hours
void addHour(int& hours) {
	hours = hours + 1;
	if (hours == 24) {
		hours = 0;
	}
}

// Adds 1 minute to time and rolls it back down to 0 if it goes up to 60 and adds 1 hour
void addMinute(int& hours, int& minutes) {
	minutes = minutes + 1;
	if (minutes == 60) {
		minutes = 0;
		addHour(hours);
	}
}

// Adds 1 second to time and rolls it back down to 0 if it goes up to 60 and adds 1 minute
void addSecond(int& hours, int& minutes, int& seconds) {
	seconds = seconds + 1;
	if (seconds == 60) {
		seconds = 0;
		addMinute(hours, minutes);
	}
}

// Main logic that processes loop to gather user input for the menu selection
void ProcessInput(int& hours, int& minutes, int& seconds) {

	// Local variables used for the loop
	bool exit = false;
	int selection = 0;

	// Loop continues to iterate until the user selects option 4 to exit
	while (!exit) {

		// Re-display the clock, menu options and ask the user for an input
		DisplayClock(hours, minutes, seconds);
		DisplayMenu();
		cin >> selection;

		// Takes user input to determine which function to run
		switch (selection) {

		// Adds 1 hour
		case 1:
			addHour(hours);
			break;

		// Adds 1 minute and 1 hour when necessary
		case 2:
			addMinute(hours, minutes);
			break;

		// Adds 1 second and 1 minute and 1 hour when necessary
		case 3:
			addSecond(hours, minutes, seconds);
			break;

		// Exits the program
		case 4:
			cout << "Thank you. Goodbye" << endl;
			exit = true;
			break;
		
			// If any option other than 1 - 4 are selected, it ouputs an error and return to user selection
		default:
			cout << "Invalid response. Please try again" << endl;
		}
	}
}

// Main that begins the program
int main() {

	ProcessInput(hours, minutes, seconds);
	
	return 0;
}
