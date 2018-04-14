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
#ifndef DICE_H
#define DICE_H
#include <iostream>
#include <random>
#include "colour.h"

struct Dice{
	const Colour c;
	int face; 
	int roll();
	bool equals(Dice& d);
	friend std::ostream& operator<<(std::ostream &os, const Dice& d);
};
#endif // DICE_H