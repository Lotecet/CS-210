/* Mitchell Gossman
   CS 210-R4728
   04/02/24 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to convert Fahrenheit to Celsius
double FahrToCel(double fahrTemp) {
	return ((fahrTemp - 32.0) * (5.0 / 9.0));
}

int main() {

	ifstream inFS;  // input file stream
	ofstream outFS; // output file stream
	string cityFromFile = ""; // city name
	int tempInFare = 0; // temp in the city 

	// Message announcing which files to open
	cout << "Opening file FahrenheitTemperature.txt and CelsiusTemperature.txt" << endl;


	// Opens the input file FahrenheitTemperature.txt
	inFS.open("FahrenheitTemperature.txt");
	// Opens the output file CelsiusTemperature.txt
	outFS.open("CelsiusTemperature.txt");


	// Could not open the input file
	if (!inFS.is_open()) {
		cout << "Could not open the file FahrenheitTemperature.txt";
		return 1;
	}

	// Could not open the output file
	if(!outFS.is_open()) {
		cout << "Could not open the file CelsiusTemperature.txt";
		return 1;
	}


	// Assuming the file was found
	cout << "Reading the FahrenheitTemperature file" << endl;
	while (!inFS.eof()) {
		
		// Read from the input file
		inFS >> cityFromFile;
		inFS >> tempInFare;

		// write to the output file
		outFS << cityFromFile << " ";
		outFS << FahrToCel(tempInFare) << endl;

	}

	// Remove newlines
	inFS.ignore();

	// Clear the error state
	inFS.clear();

	// close all files
	cout << "Closing all files";
	inFS.close();
	outFS.close();

	// Announcing the program is done
	cout << "Job Complete";


	return 0;
}
