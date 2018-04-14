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
#include "qwixxrow.h"

template<class T, Colour V>
QwixxRow<T,V>& QwixxRow<T,V>::operator+=(const RollOfDice& rd){
    if((int(rd)<2)||int(rd)>12)
        throw;
    for (auto ci = this->container.begin(); ci != this->container.end(); ci++){
        if(*ci == int(rd)){
            *ci = 1;
        }
    }
    return *this;
}

/*
// Function: operator<<
// Returns: ostream object (chaining)
// Parameters: ostream object and qwixxrow object
// Description: overloads the << operator to print a qwixxrow object 
*/
template<class T, Colour V>
std::ostream& operator<<(std::ostream &os, const QwixxRow<T,V>& row){
    
    for (typename T::const_iterator ci = row.container.cbegin(); ci != row.container.end(); ci++){
        if(*ci<10 && *ci>1){
            os << " " << *ci << "|";
        }
        else if(*ci<13 && *ci>9){
            os << *ci << "|";
        }
        else if(*ci==1){
            os << "XX" << "|";
        }
        else if(*ci==0){
            os << " U";
        }
        else{
            os << " L";
        }
    }

    return os;
}

/*
// Function: validate
// Returns: true if a roll of dice can be scored in a specifed row and false otherwise
// Parameters: a roll of dice object and a qwixxrow object
// Description: checks to see whether a roll of dice value can be scored in the desired row
// according to the rules
*/
template<class T, Colour V>
bool validate(RollOfDice& rd, QwixxRow<T,V> row){
    bool flag1 = false;
    bool flag2 = true;
    for (typename T::iterator ci = row.container.begin(); ci != row.container.end(); ci++){
        if(flag1){
            if((*ci) ==1 ){ //Check to see if there are any numbers to the right of the desired index
                flag2 = false; //Return false given that the roll of dice values must be placed in ascending order
            }
        }
        if((*ci) == rd){ //Move the iterator to the desired index
            flag1 = true;
        }
    }
    if(flag2 == false)
        std::cout << "The values must be placed in ascending order" << std::endl;
    return flag2;
}

//#define TEST_QWIXXROW
#ifdef TEST_QWIXXROW
int main(){
    std::cout << "Testing default constructor" << std::endl;
    std::cout << "------------------------------" << std::endl;
    QwixxRow<std::vector<int>, Colour::RED> qr({2, 3, 4, 5, 6, 7, 8, 9, 10, 11 ,12, 0});
    std::cout << "Testing overloaded insertion operator" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << qr << std::endl;
    std::cout << "Testing validate function" << std::endl;
    std::cout << "------------------------------" << std::endl;
    RollOfDice rd;
    rd.multDice.push_back(Dice{Colour::RED, 5});
    rd.multDice.push_back(Dice{Colour::WHITE, 2});
    std::cout << validate(rd, qr) << std::endl;
    std::cout << qr << std::endl;
    return 0;
}
#endif