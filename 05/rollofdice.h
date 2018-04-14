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
#ifndef ROLLOFDICE_H
#define ROLLOFDICE_H
#include <iostream>
#include <vector>
#include "dice.cpp"

struct RollOfDice{
	std::vector<Dice> multDice;
	operator int() const;
	void roll();
	RollOfDice pair(Dice d1, Dice d2);
	friend std::ostream& operator<<(std::ostream &os, const RollOfDice& rod);
};
#endif // ROLLOFDICE_H
