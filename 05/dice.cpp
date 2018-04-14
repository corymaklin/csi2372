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
#include "dice.h"

static std::random_device r_dd;  //Will be used to obtain a seed for the random number engine
static std::mt19937 gen(r_dd()); //Standard mersenne_twister_engine seeded with rd()
static std::uniform_int_distribution<> dis(1, 6); //Ensures that the number generated is between 1 and 6

/*
// Function: roll
// Parameters: nothing
// Returns: A randomly generated number between 1 and 6
// Description: Simulates rolling a dice
*/
int Dice::roll(){
    /*
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 6); //Ensures that the number generated is between 1 and 6
    */
	face = dis(gen);
	return face;
}
/*
// Function: equals
// Parameters: a dice object
// Returns: true if the two faces are equals and false otherwise
// Description: Compares the faces of two dice objects
*/
bool Dice::equals(Dice& d){
	return ((c == d.c) && (face == d.face)); //Checks to see if the faces of two dice are equal to eachother 
}
/*
// Function: operator<<
// Parameters: A dice object and an ostream object
// Returns: The ostream object (chaining)
// Description: Overloads the << operator such that the color and face
// of a dice object is outputed to the terminal
*/
std::ostream& operator<<(std::ostream &os, const Dice& d){
	//Prints the colour of the dice
	switch( d.c )
		{
		case Colour::RED:
    		os << "Red:	";
    		break;
		case Colour::YELLOW:
    		os << "Yellow:	";
    		break;
		case Colour::GREEN:
    		os << "Green:	";
    		break;
		case Colour::BLUE:
			os << "Blue:	";
			break;
		case Colour::WHITE:
			os << "White:	";
			break;
		default:
    		return os;
		  }
	//Prints the face of the dice
  	os << d.face << std::endl;
  	return os;
}

//#define TEST_DICE
#ifdef TEST_DICE
int main(){
	std::cout << "Testing default constructor" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	Dice d{Colour::RED, 1};

	std::cout << "Testing overloaded << operator" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << d << std::endl;

	std::cout << "Testing roll function" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << d << std::endl;
	std::cout << "Rolling..." << std::endl;
	d.roll();
	std::cout << d << std::endl;

	std::cout << "Testing equals function" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	Dice d2{Colour::BLUE, 3};
	std::cout << d.equals(d2) << std::endl;
}
#endif