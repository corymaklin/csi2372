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
#ifndef PLAYER_H
#define PLAYER_H
#include "qwixxscoresheet.cpp"
#include "qwintoscoresheet.cpp"

class Player{
	protected:
	bool active; // Variable which indicates whether it's the player's turn to roll the dice
	public:
	Player(){
		active = false;
	}
	void setActive(bool flag){
		active = flag;
	}
	bool getActive(){
		return active;
	}
	virtual void inputBeforeRoll(RollOfDice& rd) = 0;
	virtual void inputAfterRoll(RollOfDice& rd) = 0;
};
#endif // PLAYER_H