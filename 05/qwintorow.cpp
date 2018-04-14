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
#include "qwintorow.h"

/*
// Function: operator[]
// Returns: The reference to an integer
// Parameters: The index of the array to be accessed
// Description: Overloads the [] operator such that we can access the elements of the array
// contained within the QwintoRow object directly
*/
template<Colour T>
int& QwintoRow<T>::operator[] (const int index){
    return container[index];
}
/*
// Function: print
// Returns: Nothing
// Parameters: The value of a specific position in a given row
// Description: Prints the value at a specific index of a row with the proper spacing
*/
void print(const int elem){
    if(elem<10 && elem>1){
        std::cout << " " << elem;
    }
    else if(elem<19 && elem>9){
        std::cout << elem;
    }
    else{
        std::cout << "  ";
    }
}
/*
// Function: operator<<
// Returns: ostream object
// Parameters: an ostream object and a qwintorow object with the colour red
// Description: Overloads the << operator to print the red row with the correct properties
*/
std::ostream& operator<<(std::ostream &os, const QwintoRow<Colour::RED>& row){
    os << "|";
    print(row.container[0]);
    os << "%";
    print(row.container[1]);
    os << "%";
    print(row.container[2]);
    os << "|XX|";
    print(row.container[3]);
    os << "%";
    print(row.container[4]);
    os << "%";
    print(row.container[5]);
    os << "|";
    print(row.container[6]);
    os << "|";
    print(row.container[7]);
    os << "|";
    print(row.container[8]);
    os << "|";
    return os;
}
/*
// Function: operator<<
// Returns: ostream object
// Parameters: an ostream object and a qwintorow object with the colour yellow
// Description: Overloads the << operator to print the yellow row with the correct properties
*/
std::ostream& operator<<(std::ostream &os, const QwintoRow<Colour::YELLOW>& row){
    os << "|";
    print(row.container[0]);
    os << "|";
    print(row.container[1]);
    os << "|";
    print(row.container[2]);
    os << "|";
    print(row.container[3]);
    os << "|";
    print(row.container[4]);
    os << "|XX|";
    print(row.container[5]);
    os << "|";
    print(row.container[6]);
    os << "%";
    print(row.container[7]);
    os << "%";
    print(row.container[8]);
    os << "|";
    return os;
}
/*
// Function: operator<<
// Returns: ostream object
// Parameters: an ostream object and a qwintorow object with the colour blue
// Description: Overloads the << operator to print the blue row with the correct properties
*/
std::ostream& operator<<(std::ostream &os, const QwintoRow<Colour::BLUE>& row){
    os << "|";
    print(row.container[0]);
    os << "|";
    print(row.container[1]);
    os << "%";
    print(row.container[2]);
    os << "%";
    print(row.container[3]);
    os << "|XX|";
    print(row.container[4]);
    os << "|";
    print(row.container[5]);
    os << "|";
    print(row.container[6]);
    os << "|";
    print(row.container[7]);
    os << "%";
    print(row.container[8]);
    os << "%";
    return os;
}
/*
// Function: validate
// Returns: true if the roll of dice can be scored at 
// that position accroding to the rules and false otherwise
// Parameters: a roll of dice object and the position in a row specified by the player
// Description: Ensures that a roll of dice is being scored according to the rules of the game
*/
template<Colour T>
bool QwintoRow<T>::validate(RollOfDice& rd, int index){
    if(container[index] != 0){ //Check to see if a number has already been placed at the given index
        return false;
    }
    bool flag = true;
    int value = rd;
    // Ensure that no number is scored in the same row more than once
    for(int k=0; k<9; k++){
        if(value == container[k]){
            flag = false;
        }
    }
    //Numbers must be placed in ascending order
    for(int i=index; i<9; i++)
    // Check to see if there are numbers smaller than the current roll of dice to the right of the specified index
        if((container[i] > 0) && (container[i] < value)) 
            flag = false;
    
    for(int j=index; j>=0; j--)
    // Check to see if there are numbers larger than the current roll of dice to the left of the specified index
        if((container[j] > value) && (container[j] >0))
            flag = false;
    
    return flag;
}

//#define TEST_QWINTOROW
#ifdef TEST_QWINTOROW
int main(){
    std::cout << "Testing default constructor" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    QwintoRow<Colour::RED> qr;

    std::cout << "Testing overloaded << operator" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << qr << std::endl;

    std::cout << "Testing overloaded [] operator" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "The value of the first element is: " << qr[3] << std::endl;

    std::cout << "Testing validate function" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    RollOfDice rd1;
    rd1.multDice.push_back(Dice{Colour::RED, 1});
	rd1.multDice.push_back(Dice{Colour::YELLOW, 2});
	rd1.multDice.push_back(Dice{Colour::BLUE, 3});
    std::cout << "Entering 6 at position 3 would result in: " << qr.validate(rd1, 3) << std::endl;
    qr[3] = 6;
    std::cout << qr << std::endl;

	RollOfDice rd2;
	rd2.multDice.push_back(Dice{Colour::RED, 1});
	rd2.multDice.push_back(Dice{Colour::YELLOW, 1});
	rd2.multDice.push_back(Dice{Colour::BLUE, 1});
    std::cout << "Entering 3 at position 4 would result in: " << qr.validate(rd2, 4) << std::endl;
    std::cout << qr << std::endl;    

	RollOfDice rd3;
	rd3.multDice.push_back(Dice{Colour::RED, 1});
	rd3.multDice.push_back(Dice{Colour::YELLOW, 4});
	rd3.multDice.push_back(Dice{Colour::BLUE, 4});
    std::cout << "Entering 9 at position 4 would result in: " << qr.validate(rd3, 4) << std::endl;
    qr[4] = 9;
    std::cout << qr << std::endl;
    
	RollOfDice rd4;
	rd4.multDice.push_back(Dice{Colour::RED, 1});
	rd4.multDice.push_back(Dice{Colour::YELLOW, 1});
	rd4.multDice.push_back(Dice{Colour::BLUE, 1});
	std::cout << "Entering 3 at position 2 would result in: " << qr.validate(rd4, 2) << std::endl;
    qr[2] = 3;
    std::cout << qr << std::endl;
    
}
#endif