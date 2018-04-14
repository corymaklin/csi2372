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
#ifndef SCORESHEET_H
#define SCORESHEET_H
#include <string>
#include "rollofdice.cpp"

class ScoreSheet{
	protected:
	unsigned char fAttempts; //The number of failed throws 
	int oScore; //The total number of points at the end of the game
	virtual int calcTotal(int count) = 0; //Calculates the total number of points accumulated at the end of the game
	public:
	std::string name; //The name of the player who posesses the scoresheet
	ScoreSheet(std::string _name) : name(_name), fAttempts(0), oScore(0) {}
	virtual bool score(RollOfDice& rd, Colour c, int position=-1) = 0; //Attempts to place the roll of dice value in the desired row 
	virtual void setTotal() = 0; // Calls calcTotal 
	std::string getName(){ return name; }
	void incFailedAttempts(){ fAttempts++; }
	int getFailedAttempts() const { return fAttempts; }
};
#endif // SCORESHEET_H
