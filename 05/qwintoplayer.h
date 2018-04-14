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
#ifndef QWINTOPLAYER_H
#define QWINTOPLAYER_H
#include "player.h"

class QwintoPlayer : public Player{
public:
    QwintoScoreSheet qwintoSheet;
    QwintoPlayer(const QwintoScoreSheet& _qwintoSheet);
	void inputBeforeRoll(RollOfDice& rd);
	void inputAfterRoll(RollOfDice& rd);
};
#endif // QWINTOPLAYER_H