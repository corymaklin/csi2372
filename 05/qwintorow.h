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
#ifndef QWINTOROW_H
#define QWINTOROW_H
#include "colour.h"
#include <iostream>
//#include "rollofdice.cpp" //Added

template <Colour T> 
class QwintoRow{
public: 
	int container[9]; //The |XX| doesn't have an index
	//Added
	QwintoRow(){
		for(int i =0; i<9; i++)
			container[i] = 0;
	}
	friend std::ostream& operator<<(std::ostream &os, const QwintoRow& row);
	int& operator[] (const int index);
	bool validate(RollOfDice& rd, int index);
};
#endif // QWINTOROW_H