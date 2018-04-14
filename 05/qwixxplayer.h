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
#ifndef QWIXXPLAYER_H
#define QWIXXPLAYER_H
#include "player.h"

class QwixxPlayer : public Player{
	public:
	QwixxScoreSheet qwixxSheet;
	QwixxPlayer(const QwixxScoreSheet& _qwixxSheet);
	void inputBeforeRoll(RollOfDice& rd);
	void inputAfterRoll(RollOfDice& rd);
};
#endif // QWIXXPLAYER_H