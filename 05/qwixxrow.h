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
#ifndef QWIXXROW_H
#define QWIXXROW_H
#include "colour.h"
#include "rollofdice.h"
#include <iostream>
#include <vector>
#include <list>

template <class T, Colour V> 
class QwixxRow 
{	
	public:
	T container;
	QwixxRow(T _container) : container(_container), count(0) {}
	unsigned char count; //Incremented whenever a number is placed in a row, used for calculating points
	void incCount() { count++; }
	friend std::ostream& operator<<(std::ostream &os, QwixxRow<T,V>& row);
	QwixxRow<T,V>& operator+=(const RollOfDice& rd);
};
#endif // QWIXXROW_H
