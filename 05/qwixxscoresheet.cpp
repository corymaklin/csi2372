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
#include "qwixxscoresheet.h"
bool QwixxScoreSheet::lockedRed = false;
bool QwixxScoreSheet::lockedYellow = false;
bool QwixxScoreSheet::lockedGreen = false;
bool QwixxScoreSheet::lockedBlue = false;

//Constructor which initializes the red and yellow rows as vectors with ascending numbers and
//the green and yellow rows as lists in descending order
QwixxScoreSheet::QwixxScoreSheet(std::string _name) : ScoreSheet(_name), 
row1({2, 3, 4, 5, 6, 7, 8, 9, 10, 11 ,12, 0}), row2({2, 3, 4, 5, 6, 7, 8, 9, 
10, 11 ,12, 0}), row3({12, 11, 10, 9, 8, 7, 6, 5, 4, 
3, 2, 0}), row4({12, 11, 10, 9, 8, 7, 6, 5, 4, 
3, 2, 0}){}
/*
// Function: calcTotal
// Returns: returns returns a value based off the predefined scoring table
// Parameters: the number of entries in a given row
// Description: calculates a portion of the total score
*/
int QwixxScoreSheet::calcTotal(int count){
	switch (count) {
	case 0:
		return 0;
	case 1:
		return 1;
	case 2:
		return 3;
	case 3:
		return 6;
	case 4:
		return 10;
	case 5:
		return 15;
	case 6:
		return 21;
	case 7:
		return 28;
	case 8:
		return 36;
	case 9:
		return 45;
	case 10:
		return 55;
	case 11: 
		return 66;
	case 12:
		return 78;
	default:
		return -100;
	}
}
/*
// Function: score
// Returns: returns true if a roll of dice value can be entered in the desired row
// Parameters: roll of dice object, the colour of the row the player would like to select, 
// the position is used for the qwinto game
// Description: updates the row according to the roll of dice value
*/
bool QwixxScoreSheet::score(RollOfDice& rd, Colour c, int position){
	bool flag = false;
	if(c==Colour::RED){
		if(validate(rd, row1)){
			row1+=rd;
			row1.count++;
			flag = true;
			if((++row1.count == 5)&&(row1.container[10] == 1)){ 
				QwixxScoreSheet::lockedRed = true;
				row1.container.back() = -1;
				row1.count++; //Locked counts as 1 entry 
			}
		}
	}
	else if(c==Colour::YELLOW){
		if(validate(rd, row2)){
			row2+=rd;
			row2.count++;
			flag = true;
			if((++row2.count == 5)&&(row2.container[10] == 1)){
				QwixxScoreSheet::lockedYellow = true;
				row2.container.back() = -1;
				row2.count++; //Locked counts as 1 entry
			}
		}
	}
	else if(c==Colour::GREEN){
		if(validate(rd, row3)){
			row3+=rd;
			row3.count++;
			flag = true;
			if(row3.count == 5){
				std::list<int>::iterator it = row3.container.begin();
				std::advance(it, 10);
				if(*it == 1){
					QwixxScoreSheet::lockedBlue = true;
					row3.container.back() = -1;
					row3.count++; //Locked counts as 1 entry
				}
			}
		}
	}
	else{
		if(validate(rd, row4)){
			row4+=rd;
			row4.count++;
			flag = true;
			if(row4.count == 5){
				std::list<int>::iterator it = row4.container.begin();
				std::advance(it, 10);
				if(*it == 1){
					QwixxScoreSheet::lockedBlue = true;
					row4.container.back() = -1;
					row4.count++; //Locked counts as 1 entry
				}
			}
		}
	}
	  return flag;
}
/*
// Function: setTotal
// Returns: nothing
// Parameters: nothing
// Description: calculates and set the total score to be displayed at the end of the game
*/
void QwixxScoreSheet::setTotal(){
	oScore += calcTotal(row1.count) + calcTotal(row2.count) + calcTotal(row3.count)
		+ calcTotal(row4.count) - (fAttempts * 5);
}
/*
// Function: operator<<
// Returns: ostream object (chaining)
// Parameters: ostream object and a qwixxscoresheet object
// Description: overloads the << operator to print a qwixxscoresheet object
*/
std::ostream& operator<<(std::ostream &os, const QwixxScoreSheet& qqs){
	os << "Player name: " << qqs.name;
	if(qqs.oScore != 0) 
	os << "		Points: " << qqs.oScore;
	os << std::endl;
	os << "	------------------------------------" << std::endl;
	os << "Red	|" << qqs.row1 << std::endl;
	os << "	------------------------------------" << std::endl;
	os << "Yellow	|" << qqs.row2 << std::endl;
	os << "	------------------------------------" << std::endl;
	os << "Green	|" << qqs.row3 << std::endl;
	os << "	------------------------------------" << std::endl;
	os << "Blue	|" << qqs.row4 << std::endl;
	os << "	------------------------------------" << std::endl;
	os << "Failed throws: ";
	for(int i=0; i< qqs.fAttempts; i++){
		os << (i+1) << " ";
	}
	os << std::endl;
	return os;
}
/*
// Function: operator!
// Returns: true if the game is over and false otherwise
// Parameters: a qwixxscoresheet object
// Description: overloads the ! operator, checks to see if the game is over according to the rules
*/
bool operator!(const QwixxScoreSheet& ss){
	bool flag1 = false;
	bool flag2 = false;
	//Check for two locked rows
	int count = 0;
	if(QwixxScoreSheet::lockedRed == true)
		count++;
	if(QwixxScoreSheet::lockedYellow == true)
		count++;
	if(QwixxScoreSheet::lockedGreen == true)
		count++;
	if(QwixxScoreSheet::lockedBlue == true)
		count++;
	flag1 = count > 1;
	//Check for 4 failed throws
	flag2 = ss.fAttempts == 4;

	return flag1 || flag2;
}

//#define TEST_QWIXXSCORESHEET
#ifdef TEST_QWIXXSCORESHEET
int main(){

	std::cout << "Testing constructor" << std::endl;
	std::cout << "------------------------------" << std::endl;
	QwixxScoreSheet qss("Lang");

	std::cout << "Testing overloaded insertion operator" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << qss << std::endl;

	std::cout << "Testing score function" << std::endl;
	std::cout << "------------------------------" << std::endl;
	RollOfDice rd;
	rd.multDice.push_back(Dice{Colour::RED, 5});
	rd.multDice.push_back(Dice{Colour::WHITE, 2});
	qss.score(rd, Colour::RED);
	std::cout << qss << std::endl;

	RollOfDice rd2;
	rd2.multDice.push_back(Dice{Colour::RED, 3});
	rd2.multDice.push_back(Dice{Colour::WHITE, 1});
	qss.score(rd2, Colour::RED);
	std::cout << qss << std::endl;

	RollOfDice rd3;
	rd3.multDice.push_back(Dice{Colour::RED, 6});
	rd3.multDice.push_back(Dice{Colour::WHITE, 6});
	qss.score(rd3, Colour::RED);
	std::cout << qss << std::endl;

	std::cout << "Testing overloaded not operator" << std::endl;
	std::cout << "------------------------------" << std::endl;
	
	if(!qss)
		std::cout << "Gameover!" << std::endl;
	else
		std::cout << "Game currently in session" << std::endl;
	
	QwixxScoreSheet::lockedRed = true;
	QwixxScoreSheet::lockedYellow = true;

	if(!qss)
		std::cout << "Gameover!" << std::endl;
	else
		std::cout << "Game currently in session" << std::endl;

	QwixxScoreSheet::lockedRed = false;
	QwixxScoreSheet::lockedYellow = false;

	for(int i=0; i<4; i++)
		qss.incFailedAttempts();

	if(!qss)
		std::cout << "Gameover!" << std::endl;
	else
		std::cout << "Game currently in session" << std::endl;

	std::cout << "Testing setTotal function" << std::endl;
	std::cout << "------------------------------" << std::endl;
	qss.setTotal();
	std::cout << qss << std::endl;

	return 0;
}
#endif