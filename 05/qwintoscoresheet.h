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
#ifndef QWINTOSCORESHEET_H
#define QWINTOSCORESHEET_H
#include "scoresheet.h"
#include "qwintorow.cpp"

class QwintoScoreSheet : public ScoreSheet{
    QwintoRow<Colour::RED> row1;
	QwintoRow<Colour::YELLOW> row2;
    QwintoRow<Colour::BLUE> row3;
    virtual int calcTotal(int count);
public:
    QwintoScoreSheet(std::string _name);
    friend std::ostream& operator<<(std::ostream &os, const QwintoScoreSheet& qss);
    virtual bool score(RollOfDice& rd, Colour c, int position=-1);
    virtual void setTotal();
    friend bool operator!(const QwintoScoreSheet& ss);
};
#endif // QWINTOSCORESHEET_H