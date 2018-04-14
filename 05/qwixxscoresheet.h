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
#include "scoresheet.h"
#include <iostream>
#include <vector>
#include <list>
#include "qwixxrow.cpp"
#ifndef QWIXXSCORESHEET_H
#define QWIXXSCORESHEET_H

class QwixxScoreSheet : public ScoreSheet{
	protected:
	virtual int calcTotal(int count);
	public:
	QwixxRow<std::vector<int>, Colour::RED> row1;
	QwixxRow<std::vector<int>, Colour::YELLOW> row2;
	QwixxRow<std::list<int>, Colour::GREEN> row3;
	QwixxRow<std::list<int>, Colour::BLUE> row4;
	static bool lockedRed;
	static bool lockedYellow;
	static bool lockedGreen;
	static bool lockedBlue;
	QwixxScoreSheet(std::string _name);
	virtual bool score(RollOfDice& rd, Colour c, int position=-1);
	virtual void setTotal();
	friend std::ostream& operator<<(std::ostream &os, const QwixxScoreSheet& qss);
	friend bool operator!(const QwixxScoreSheet& ss);
};	
#endif // QWIXXSCORESHEET_H