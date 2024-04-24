/* Mitchell Gossman
   CS 210-R4728
   04/20/24 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>  // used to manage input and output formatting
#include "Header.h"
using namespace std;

// Function to create lines for the DisplayMenuOption() and InputError() functions
string Filler(int count, char s) {
	string output = "";

	for (int i = 0; i < count; ++i) {
		output = output + s;
	}
	return output;
}

// Displays the Main Menu selection choices for the user
void DisplayMenuOption() {
	cout << Filler(50, '*') << endl;
	cout << "Please make a selection. 1-4" << endl;
	cout << "Option 1 - Enter a word" << endl;
	cout << "Option 2 - Print the list with numbers" << endl;
	cout << "Option 3 - Print the list in a Histogram" << endl;
	cout << "Option 4 - Exit the Program" << endl;
	cout << Filler(50, '*') << endl;
}

// Displays the Error message if the user doesn't enter numbers 1-4 in the DisplayMenuOption() function
void InputError() {
	cout << Filler(50, '*') << endl;
	cout << "*** Error! Please make a Valid Selection '1-4' ***" << endl;  // 50 spaces
	cout << Filler(50, '*') << endl;
}

// Main function to run the program
int main() {
	
	// Declared main program variables and class
	Groceries inventory;
	int selection = 0;
	bool exitProgram = false;
	
	// use constructor to create the new class
	inventory.Grocery();

	// Create all the files for the new class item
	inventory.InventoryItem();
	
	// Main loop that runs the main menu selection
	while (exitProgram != true) {

		// Display all the menu options available
		DisplayMenuOption();
		cout << "Your selection:";
		cin >> selection;
		cout << Filler(50, '#') << endl << endl;

		// Logic will loop until the user makes a selection of 4
		switch (selection) {
		case 1: 
			inventory.MenuOption1();
			break;

		case 2: 
			inventory.MenuOption2();
			break;

		case 3: 
			inventory.MenuOption3();
			break;

		case 4: 
			exitProgram = true;
			break;
		
		default: 
			InputError();
		}
	}
	// Program will now end, Displays Goodbye message
	cout << "Goodbye";
	
	return 0;
}
