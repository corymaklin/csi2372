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
#include "qwintoplayer.h"

QwintoPlayer::QwintoPlayer(const QwintoScoreSheet& _qwintoSheet) : qwintoSheet(_qwintoSheet){}
/*
// Function: intputBeforeRoll
// Returns: nothing
// Parameters: a roll of dice object
// Description: Creates a roll of dice object based off what colour of dice the active player would
// like to roll. It will then roll all the dice in the object, display the values on the screen and 
// ask whether the active player would like to re-roll
*/
void QwintoPlayer::inputBeforeRoll(RollOfDice& rd){
    if(active == true){
        std::cout << qwintoSheet;
        bool flag1 = false;
        do{
            std::cout << "Would you like to roll the red die? y/n" << std::endl;
            char rollr;
            std::cin >> rollr;
            if(rollr == 'y' || rollr == 'Y'){
                rd.multDice.push_back(Dice{Colour::RED, 1});
                flag1 = true;
            }
            std::cout << "Would you like to roll the yellow die? y/n" << std::endl;
            char rolly;
            std::cin >> rolly;
            if(rolly == 'y' || rolly == 'Y'){
                rd.multDice.push_back(Dice{Colour::YELLOW, 1});
                flag1 = true;
            }
            std::cout << "Would you like to roll the blue die? y/n" << std::endl;
            char rollb;
            std::cin >> rollb;
            if(rollb == 'y' || rollb == 'Y'){
                rd.multDice.push_back(Dice{Colour::BLUE, 1});
                flag1 = true;
            }
            if(flag1==false)
                std::cout << "You must choose to roll at least one die" << std::endl;
        }while(flag1==false);
        rd.roll();
        std::cout << rd;
        std::cout << "Would you like to re-roll? y/n" << std::endl;
        char reroll;
        std::cin >> reroll;
        if(reroll == 'y' || reroll == 'Y'){
            rd.roll();
            std::cout << rd;
        }
    }
}
/*
// Function: inputAfterRoll
// Returns: nothing
// Parameters: Roll of dice object
// Description: Prompts the user for the enter whether they would like to score the dice or not and if
// so in what colour row and in which position. The function behaves differently for an active player in
// that it increments the number of failed throws if they fail or pass on scoring a dice
*/
void QwintoPlayer::inputAfterRoll(RollOfDice& rd){
    if(active == true){
        bool flag1 = false;
        do{
            std::cout << "Would you like to score the dice? y/n" << std::endl;
            char sc;
            std::cin >> sc;
            if(sc == 'Y' || sc == 'y'){
                std::cout << "Enter the colour of the row you'd like to select r/y/b" << std::endl;
                char col;
                std::cin >> col;
                Colour colour = charToColour(col);
                bool contains = false;
                for(int i=0; i<rd.multDice.size(); i++){
                    if(colour == rd.multDice[i].c)
                    contains = true;
                }
                if(contains){
                    bool flag2 = false;
                    while(flag2 == false){
                        std::cout << "Enter the index you'd like to select " << std::endl;
                        int index;
                        std::cin >> index;
                        if(index > 8 || index < 0)
                            std::cout << "You must enter a number between 0 and 8" << std::endl;
                        else{
                            if(colour == Colour::RED)
                                flag1 = qwintoSheet.score(rd, colour, index);
                            else if(colour == Colour::YELLOW)
                                flag1 = qwintoSheet.score(rd, colour, index);
                            else
                                flag1 = qwintoSheet.score(rd, colour, index);
                        
                            std::cout << qwintoSheet;
                            flag2 = true;
                        }
                    }
                }
                else{
                    std::cout << "You must enter a row whose colour corresponds to one of the dice rolled" << std::endl;
                }
            }
            else if((sc == 'n')||(sc == 'N')){
                qwintoSheet.incFailedAttempts();
                flag1 = true;
                std::cout << qwintoSheet;
            }
            else{
                std::cout << "You must enter either the character 'y' or the character 'n'" << std::endl;
            }
        }while(flag1==false);
    }
    else{
        std::cout << qwintoSheet;
        bool flag1 = false;
        while(flag1==false){
            std::cout << "Would you like to score the dice? y/n" << std::endl;
            char sc;
            std::cin >> sc;
            if(sc == 'Y' || sc == 'y'){
                std::cout << "Enter the colour of the row you'd like to select r/y/b" << std::endl;
                char col;
                std::cin >> col;
                Colour colour = charToColour(col);
                for(int i=0; i<rd.multDice.size(); i++){
                    if(colour == rd.multDice[i].c)
                    flag1 = true;
                }
                if(flag1){
                    bool flag2 = false;
                    while(flag2 == false){
                        std::cout << "Enter the index you'd like to select " << std::endl;
                        int index;
                        std::cin >> index;
                        if(index > 8 || index < 0)
                            std::cout << "You must enter a number between 0 and 8" << std::endl;
                        else{
                            if(colour == Colour::RED)
                                qwintoSheet.score(rd, colour, index);
                            else if(colour == Colour::YELLOW)
                                qwintoSheet.score(rd, colour, index);
                            else
                                qwintoSheet.score(rd, colour, index);
                        
                            std::cout << qwintoSheet;
                            flag2 = true;
                        }
                    }
                }
                else{
                    std::cout << "You must enter a colour which matches one of the dice rolled" << std::endl;
                }
            }
            else{
                flag1 = true;
            }
        }
    }
}

//#define TEST_QWINTOPLAYER
#ifdef TEST_QWINTOPLAYER
int main(){
    std::cout << "Testing constructor" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    QwintoScoreSheet qss("Lang");
    QwintoPlayer qp(qss);

    std::cout << "Testing inputBeforeRoll function" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    RollOfDice rd;
    qp.inputBeforeRoll(rd);
    qp.setActive(true);
    qp.inputBeforeRoll(rd);
    std::cout << "Testing inputAfterRoll function" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    qp.inputAfterRoll(rd);
    qp.setActive(false);
    qp.inputAfterRoll(rd);
}
#endif