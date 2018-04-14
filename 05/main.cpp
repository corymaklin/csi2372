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

#include <iostream>
#include "qwixxplayer.cpp"
#include "qwintoplayer.cpp"

int main(){
	std::cout << "Please enter a 0 for Qwinto and a 1 for Qwixx" << std::endl;
	int gameMode;
	std::cin >> gameMode;
	if(gameMode == 0){
		bool flag0 = true;
		int numPlayers;
		do{
			std::cout << "Please enter the number of players" << std::endl;
			std::cin >> numPlayers;
			if(numPlayers>0 && numPlayers<4)
			{
				flag0 = false;
			}
			else
				std::cout << "You must select a number between 1 and 3." << std::endl;
		}while(flag0);
	
		std::vector<QwintoPlayer> players;
		for(int i=0; i<numPlayers; i++){
			std::cout << "Please enter the name of player " << i << std::endl;
			std::string name;
			std::cin >> name;
			players.push_back(QwintoPlayer(QwintoScoreSheet(name)));
		}
		int turn = 0;
		bool flag = false;
		int round;
		while(flag == false){
			round = turn;
			RollOfDice rd;
			players[turn].setActive(true);
			do{
				std::cout << players[round].qwintoSheet.name <<"'s turn" << std::endl;
				players[round].inputBeforeRoll(rd);
				players[round].inputAfterRoll(rd);
				flag = !(players[round].qwintoSheet);
				round = (round + 1) % numPlayers; 
			}while((round!=turn)&&(flag == false));
			players[turn].setActive(false);
			turn = (turn + 1) % numPlayers;
		}
		std::cout << "END GAME" << std::endl; 
		for(int i=0; i<numPlayers; i++){
			players[i].qwintoSheet.setTotal();
			std::cout << players[i].qwintoSheet;
		}
	}
	else{
		std::cout << "Please enter the number of players" << std::endl;
		int numPlayers;
		std::cin >> numPlayers;
		try{
			if(numPlayers > 3 || numPlayers < 1)
			throw 0;
		} catch(...) { 
			std::cerr << "Error: You must enter a number between 1 and 3." << std::endl; 
			return 0;
		}
		std::vector<QwixxPlayer> players;
		for(int i=0; i<numPlayers; i++){
			std::cout << "Please enter the name of player " << i << std::endl;
			std::string name;
			std::cin >> name;
			players.push_back(QwixxPlayer(QwixxScoreSheet(name)));
		}
	
	int turn = 0;
	bool flag = false;
	int round;
		do{
			players[turn].setActive(true);
			round = turn;
			RollOfDice rd;
			do{
				std::cout << players[round].qwixxSheet.name <<"'s turn" << std::endl;
				players[round].inputBeforeRoll(rd);
				players[round].inputAfterRoll(rd);
				flag = !(players[round].qwixxSheet);
				round = (round + 1) % numPlayers; 	
			} while(round != turn && flag == false);
			players[turn].setActive(false);
			turn = (turn + 1) % numPlayers;
		}while(flag == false);
		std::cout << "END GAME" << std::endl; 
		for(int i=0; i<numPlayers; i++){
			players[i].qwixxSheet.setTotal();
			std::cout << players[i].qwixxSheet;
		}
	}
}
