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
#include "qwixxplayer.h"
	/*
	// Function: charToColour
	// Returns: a colour (enum)
	// Parameters: the character inputed by the user
	// Description: the player is prompted to enter the first letter of the colour they would like to select,
	// the function converts this character into a colour of type enum
	*/
	Colour charToColour(char c){
	if(c == 'r' || c == 'R')
    	return Colour::RED;
	else if(c == 'y' || c == 'Y')
    	return Colour::YELLOW;
	else if(c == 'g' || c == 'G')
    	return Colour::GREEN;
	else if(c == 'b' || c == 'B')
    	return Colour::BLUE;
	else
    	return Colour::WHITE;
	}
	/*
	// Function: QwixxPlayer
	// Returns: nothing
	// Parameters: an instance of Qwixxscoresheet 
	// Description: Copy constructor
	*/
	QwixxPlayer::QwixxPlayer(const QwixxScoreSheet& _qwixxSheet) : qwixxSheet(_qwixxSheet){}
	
	/*
	// Function: inputBeforeRoll
	// Returns: nothing
	// Parameters: a roll of dice object
	// Description: creates a roll of dice object, removing any colour dice corresponding to a locked row, 
	// rolls the dice and prints the values on to the screen 
	*/
	void QwixxPlayer::inputBeforeRoll(RollOfDice& rd){
	//The inputBeforeroll will behave differently for active players
		if(active == true){
			//Create the dice object
			rd.multDice.push_back(Dice{Colour::WHITE, 1});
			rd.multDice.push_back(Dice{Colour::WHITE, 1});
			if(QwixxScoreSheet::lockedRed == false)
				rd.multDice.push_back(Dice{Colour::RED, 1});
			if(QwixxScoreSheet::lockedYellow == false)
				rd.multDice.push_back(Dice{Colour::YELLOW, 1});
			if(QwixxScoreSheet::lockedGreen == false)
				rd.multDice.push_back(Dice{Colour::GREEN, 1});
			if(QwixxScoreSheet::lockedBlue == false)
				rd.multDice.push_back(Dice{Colour::BLUE, 1});
			//Roll the dice
			std::cout << "Rolling the dice..." << std::endl;
			rd.roll();
		}
		else{

		}	
	}
	/*
	// Function: inputAfterRoll
	// Returns: nothing
	// Parameters: a roll of dice object
	// Description: Prompts the user to choose whether they would like to score the roll of dice or not.
	// The active player is allowed to score an additional combination of a coloured and white dice. 
	// If the active player doesn't wish to or fails to score a dice it counts as a failed throw.
	*/
	void QwixxPlayer::inputAfterRoll(RollOfDice& rd){
		if(active == true){
			bool flag1 = false;
			bool flag2 = false;
			while(!(flag1 && flag2)){
				std::cout << rd;
				std::cout << qwixxSheet;
				std::cout << "Would you like to score the white dice? y/n" << std::endl;
				char yn;
				std::cin >> yn;
				if((yn == 'y') || (yn == 'Y')){
					char ch;
					std::cout << "Enter the colour of the row you'd like to select r/y/g/b" << std::endl;
					std::cin >> ch;
					Colour rowcol = charToColour(ch);
					if(rowcol != Colour::WHITE){
						std::cout << "Would you like to score an additional coloured dice? y/n" << std::endl;
						char ycol;
						std::cin >> ycol;
						if((ycol == 'y')||(ycol == 'Y')){
							std::cout << "Which coloured dice would you like to score? r/y/g/b" << std::endl;
							char dcol;
							std::cin >> dcol;
							if(charToColour(dcol) == rowcol){
								std::cout << "Enter the face of the white dice you want to select" << std::endl;
								int wface;
								std::cin >> wface;
								if(rd.multDice[0].face == wface){
									for(int i=0; i<rd.multDice.size(); i++){
										if(rd.multDice[i].c == rowcol){
											RollOfDice rd1 = pair(rd.multDice[0], rd.multDice[1]);
											RollOfDice rd2 = pair(rd.multDice[0], rd.multDice[i]);
											if((rowcol == Colour::GREEN)||(rowcol == Colour::BLUE)){
												if(rd1>rd2){
													flag1 = qwixxSheet.score(rd1, rowcol);
													flag2 = qwixxSheet.score(rd2, rowcol);
													std::cout << qwixxSheet;
												}
												else{
													std::cout << "Invalid! Remember the white dice must be entered first" << std::endl;
												}
											}
											else{
												if(rd1<rd2){
													flag1 = qwixxSheet.score(rd1, rowcol);
													flag2 = qwixxSheet.score(rd2, rowcol);
													std::cout << qwixxSheet;
												}
												else{
													std::cout << "Invalid! Remember the white dice must be entered first" << std::endl;
												}
											}
										}
									}
								}
								else{
									for(int i=0; i<rd.multDice.size(); i++){
										if(rd.multDice[i].c == rowcol){
											RollOfDice rd1 = pair(rd.multDice[0], rd.multDice[1]);
											RollOfDice rd2 = pair(rd.multDice[1], rd.multDice[i]);
											if((rowcol == Colour::GREEN)||(rowcol == Colour::BLUE)){
												if(rd1>rd2){
													flag1 = qwixxSheet.score(rd1, rowcol);
													flag2 = qwixxSheet.score(rd2, rowcol);
													std::cout << qwixxSheet;
												}
												else{
													std::cout << "Invalid, the white dice must be entered first" << std::endl;
												}
											}
											else{
												if(rd1<rd2){
													flag1 = qwixxSheet.score(rd1, rowcol);
													flag2 = qwixxSheet.score(rd2, rowcol);
													std::cout << qwixxSheet;
												}
												else{
													std::cout << "Invalid, the white dice must be entered first" << std::endl;
												}
											}
										}
									}
								}
							}
							else{
								std::cout << "You must pick the die whose colour matches the chosen row" << std::endl;
							}
						}
						else{
							flag2 = true;
							RollOfDice rd1 = pair(rd.multDice[0], rd.multDice[1]);
							flag1 = qwixxSheet.score(rd1, rowcol);
							std::cout << qwixxSheet;
						}
					}
					else{
						std::cout << "You must choose one of the available rows" << std::endl;
					}
				}
				else{
					qwixxSheet.incFailedAttempts();
					flag1 = true;
					flag2 = true;
					std::cout << qwixxSheet;
				}
			}
		}
		else{
			bool flag = false;
			while(flag == false){
				std::cout << rd;
				std::cout << qwixxSheet;
				std::cout << "Would you like to score the white dice? y/n" << std::endl;
				char yn;
				std::cin >> yn;
				if((yn == 'y') || (yn == 'Y')){
					char ch;
					std::cout << "Enter the colour of the row you'd like to select r/y/g/b" << std::endl;
					std::cin >> ch;
					Colour rowcol = charToColour(ch);
					if(rowcol != Colour::WHITE){
						RollOfDice _rd = pair(rd.multDice[0], rd.multDice[1]);
						flag = qwixxSheet.score(_rd ,rowcol);
						std::cout << qwixxSheet;
					}
					else{
						std::cout << "You must choose one of the available rows" << std::endl;
					}
				}
				else{
					flag = true;
				}
			}
		}
	}

	//#define TEST_QWIXXPLAYER
	#ifdef TEST_QWIXXPLAYER
	int main(){
		std::cout << "Testing QwixxPlayer constructor" << std::endl;
		std::cout << "------------------------------" << std::endl;
		QwixxScoreSheet qss("Lang");
		QwixxPlayer qp(qss);

		std::cout << "Testing charToColour function" << std::endl;
		std::cout << "------------------------------" << std::endl;
		Colour c = charToColour('w');
		if(c == Colour::WHITE)
			std::cout << "it worked!" << std::endl;
		else
			std::cout << "It failed" << std::endl;

		std::cout << "Testing inputBeforeRoll function" << std::endl;
		std::cout << "------------------------------" << std::endl;
		RollOfDice rd;
		qp.inputBeforeRoll(rd);
		qp.setActive(true);
		qp.inputBeforeRoll(rd);
		std::cout << rd << std::endl;
		std::cout << qp.qwixxSheet << std::endl;

		std::cout << "Testing inputAfterRoll function" << std::endl;
		std::cout << "------------------------------" << std::endl;
		qp.inputAfterRoll(rd);
		std::cout << qp.qwixxSheet << std::endl;
		qp.setActive(false);
		qp.inputAfterRoll(rd);
		std::cout << qp.qwixxSheet << std::endl;
	}
	#endif

	
	