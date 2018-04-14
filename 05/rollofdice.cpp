// ==========================================================================
// $Id: player.h,v 1 2017/11/17 9:00:00
// CSI2372 Fall 2017 Project
// ==========================================================================
// (C)opyright:
//
// Creator: Cory Maklin and Elin Fan
// Student ID: 7767320 and 7826347
// Email: CMAKL025@uottawa.ca
// ==========================================================================
#include "rollofdice.h"

/*
// Function: operator int()
// Returns: nothing
// Parameters: nothing
// Description: overloads the int() operator such that a roll of dice 
// object will be treated as an integer (for scoring)
*/
RollOfDice::operator int() const { 
	//Sums up the value of all the faces of the dice within the roll
	int sum = 0;
	for(Dice d : multDice){
		sum += d.face;
	}
	return sum; 
}
	
	/*
	// Function: roll
	// Returns: nothing
	// Parameters: nothing
	// Description: calls roll on all the dice within the roll of dice object
	*/
	void RollOfDice::roll(){
		//Calls the roll method on all the dice within the RollOfDice object
		for(Dice& d : multDice){
			d.roll();
		}
	}

	/*
	// Funciton: pair
	// Returns: a roll of dice object containing two dice
	// Parameters: two dice to be put in a roll of dice object
	// Description: takes two dice objects and copies them into a roll of dice object (used for scoring)
	*/
	RollOfDice pair(Dice d1, Dice d2){
		//Returns a RollOfDice object containing the two dice passed as arguments
		RollOfDice rd = {{d1, d2}};
		return rd;
	} 
/*
// Function: operator<< 
// Returns: ostream object
// Parameters: ostream object and roll of dice object
// Description: overloads the << operator to print all the dice within the roll of dice object
*/
std::ostream& operator<<(std::ostream &os, const RollOfDice& rod){
	//Prints all dice within the roll
	for(int i=0; i<rod.multDice.size(); i++){
		os << rod.multDice[i];
	}
	return os;
}

#ifdef TEST_ROLLOFDICE
int main(){
	std::cout << "Testing overloaded conversion operator" << std::endl;
	std::cout << "----------------------------" << std::endl;
	RollOfDice rd;
	rd.multDice.push_back(Dice{Colour::RED, 1});
	rd.multDice.push_back(Dice{Colour::YELLOW, 2});
	rd.multDice.push_back(Dice{Colour::BLUE, 3});
	int sum = 3 + rd;
	std::cout << sum << std::endl;

	std::cout << "Testing overloaded insertion operator" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << rd << std::endl;

	std::cout << "Testing roll function" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << rd << std::endl;
	rd.roll();
	std::cout << rd << std::endl;
	
	std::cout << "Testing pair function" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Dice d1 = {Colour::RED, 1};
	std::cout << "Dice 1: " << std::endl;
	std::cout << d1 << std::endl;
	Dice d2 = {Colour::BLUE, 3};
	std::cout << "Dice 2: " << std::endl;
	std::cout << d2 << std::endl;
	std::cout << "Roll of dice: " << std::endl;
	std::cout << pair(d1,d2) << std::endl;

	return 0;
}
#endif