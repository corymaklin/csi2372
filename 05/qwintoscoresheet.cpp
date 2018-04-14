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
#include "qwintoscoresheet.h"

/*
// Function: QwintoScoreSheet
// Returns: nothing
// Parameters: the name of the player
// Description: Constructor for qwintoscoresheet objects
*/
QwintoScoreSheet::QwintoScoreSheet(std::string _name) : ScoreSheet(_name){} 
/*
// Function: operator<<
// Returns: ostream object (chaining)
// Parameters: ostream object and qwintoscoresheet object
// Description: overloads the << operator to print a qwintoscoresheet object 
*/
std::ostream& operator<<(std::ostream &os, const QwintoScoreSheet& qss){
    os << "Player name: " << qss.name;
	if(qss.oScore != 0) 
	os << "		Points: " << qss.oScore;
	os << std::endl;
	os << "              ---------------------------------" << std::endl;
	os << "Red            " << qss.row1 << std::endl;
	os << "            -----------------------------------" << std::endl;
	os << "Yellow      " << qss.row2 << std::endl;
	os << "	------------------------------------" << std::endl;
	os << "Blue     " << qss.row3 << std::endl;
	os << "	---------------------------------" << std::endl;
	os << "Failed throws: ";
	for(int i=0; i< qss.fAttempts; i++){
		os << (i+1) << " ";
	}
	os << std::endl;
	return os;
}
/*
// Function: calcTotal
// Returns: the total number of points at the end of the game
// Parameters: negligeable (used for qwixxscoresheet)
// Description: Calculates the total number of points at the end of the game based off the rules
*/
int QwintoScoreSheet::calcTotal(int count){
	int sum = 0;
	count = 0;
	//Red row
	for(int i=0; i<9; i++){
		if(row1[i] != 0)
			count++;
	}
	if(count == 9){ //Row is full
		sum += row1[8];
	}
	else{
		sum += count;
	}
	//Yellow Row
	count = 0;
	for(int i=0; i<9; i++){
		if(row2[i] != 0)
			count++;
	}
	if(count == 9){ //Row is full
		sum += row2[8];
	}
	else{
		sum += count;
	}
	//Blue Row
	count = 0;
	for(int i=0; i<9; i++){
		if(row3[i] != 0)
			count++;
	}
	if(count == 9){ //Row is full
		sum += row3[8];
	}
	else{
		sum += count;
	}
	//Bonus points
	if((row1[0]>0)&&(row2[1]>0)&&(row3[2]>0))
		sum += row3[2];
	if((row1[1]>0)&&(row2[2]>0)&&(row3[3]>0))
		sum += row1[1];
	if((row1[4]>0)&&(row2[5]>0)&&(row3[6]>0))
		sum += row1[4];
	if((row1[5]>0)&&(row2[6]>0)&&(row3[7]>0))
		sum += row2[6];
	if((row1[5]>0)&&(row2[6]>0)&&(row3[7]>0))
		sum += row3[8];
	//Subtract points for failed throws
	sum -= fAttempts * 5;
    return sum;
}
/*
// Function: score
// Returns: True if a roll of dice can be scored in the desired position and false otherwise
// Parameters: roll of dice object, the colour of the row to be searched, the position the player
// would like to score
// Description: Attempts to score the value of the roll of dice at the desired position
*/
bool QwintoScoreSheet::score(RollOfDice& rd, Colour c, int position){
	bool flag = false;
	if(c == Colour::RED){
		flag = row1.validate(rd, position);
		if(flag){
			row1[position] = rd;
		}
	}
	else if(c == Colour::YELLOW){
		flag = row2.validate(rd, position);
		if(flag){
			row2[position] = rd;
		}
	}
	else{
		flag = row3.validate(rd, position);
		if(flag){
			row3[position] = rd;
		}
	}
    return flag;
}
/*
// Function: setTotal
// Returns: nothing
// Parameters: nothing
// Description: at the end of the game, it calls the internal function 
// calctotal and sets the score according to what it returns
*/
void QwintoScoreSheet::setTotal(){
	oScore = calcTotal(0);
}
/*
// Function: operator!
// Returns: true if the game is over according to the rules and false otherwise
// Parameters: a qwintoscoresheet object
// Description: overloads the ! operator and uses it to see whether the game is over
*/
//Check to see if any of the end game conditions have been met
bool operator!(const QwintoScoreSheet& ss){
	bool flag1 = false;
	bool flag2 = false;

	//Does player have two rows filled?
	int redcount=0;
	int yelcount=0;
	int bluecount=0;
	for(int i=0; i<9; i++){ // Determine the number of entries in each row
		if(ss.row1.container[i]>0)
			redcount++;
		if(ss.row2.container[i]>0)
			yelcount++;
		if(ss.row3.container[i]>0)
			bluecount++;
	}
	int redfull=0;
	int yelfull=0;
	int bluefull=0;
	if(redcount==9) //Determine if the row is full
		redfull++;
	if(yelcount==9)
		yelfull++;
	if(bluecount==9)
		bluefull++;
	flag1 = (redfull + bluefull + yelfull) > 1; //End the game if two rows are full
	//Does player have 4 failed throws?
	flag2 = ss.fAttempts == 4;
	return flag1 || flag2;
}

#ifdef TEST_QWINTOSCORESHEET
int main(){

	std::cout << "Testing constructor" << std::endl;
	std::cout << "-------------------" << std::endl;
	QwintoScoreSheet qss("Lang");
	
	std::cout << "Testing overloaded insertion operator" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << qss;

	std::cout << "Testing score function" << std::endl;
	std::cout << "-------------------" << std::endl;
	RollOfDice rd1;
	rd1.multDice.push_back(Dice{Colour::RED, 1});
	rd1.multDice.push_back(Dice{Colour::YELLOW, 2});
	rd1.multDice.push_back(Dice{Colour::BLUE, 3});
	std::cout << qss.score(rd1, Colour::RED, 3) << std::endl;
	std::cout << qss;

	RollOfDice rd2;
	rd2.multDice.push_back(Dice{Colour::RED, 1});
	rd2.multDice.push_back(Dice{Colour::YELLOW, 1});
	rd2.multDice.push_back(Dice{Colour::BLUE, 1});
	std::cout << qss.score(rd2, Colour::RED, 4) << std::endl;
	std::cout << qss;

	RollOfDice rd3;
	rd3.multDice.push_back(Dice{Colour::RED, 1});
	rd3.multDice.push_back(Dice{Colour::YELLOW, 4});
	rd3.multDice.push_back(Dice{Colour::BLUE, 4});
	std::cout << qss.score(rd3, Colour::RED, 4) << std::endl;
	std::cout << qss;

	RollOfDice rd4;
	rd4.multDice.push_back(Dice{Colour::RED, 1});
	rd4.multDice.push_back(Dice{Colour::YELLOW, 1});
	rd4.multDice.push_back(Dice{Colour::BLUE, 1});
	std::cout << qss.score(rd4, Colour::RED, 2) << std::endl;
	std::cout << qss;

	std::cout << "Testing setTotal function" << std::endl;
	std::cout << "-------------------" << std::endl;
	qss.setTotal();
	std::cout << qss;

	std::cout << "Testing overloaded not operator" << std::endl;
	std::cout << "-------------------" << std::endl;
	if(!qss)
		std::cout << "Gameover!" << std::endl;
	else
		std::cout << "Game currently in session" << std::endl;

	for(int i=0; i<4; i++)
		qss.incFailedAttempts();

	if(!qss)
		std::cout << "Gameover!" << std::endl;
	else
		std::cout << "Game currently in session" << std::endl;

	return 0;
}
#endif