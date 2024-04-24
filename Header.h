/* Mitchell Gossman
   CS 210-R4728
   04/20/24 */

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>	


#ifndef HEADER_H
#define HEADER_H

using namespace std;

//Class Declarations
class Groceries {
private:
	string fileInput;
	string fileOutput;
	string name;
	int quantity;
	map<string, int> grocContainer;
	

public:
	// Constructor with no values
	void Grocery();

	// Constructor with values
	void Grocery(string fileInput, string fileOutput);

	// Print menu option 1
	void MenuOption1();

	// Print menu option 2
	void MenuOption2();

	// Print menu option 3
	void MenuOption3();
	
	// Takes the input file and reads records
	void InventoryItem();
	
	};
#endif
