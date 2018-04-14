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

struct RandomDice{
    static std::random_device r_dd;  //Will be used to obtain a seed for the random number engine
    static std::mt19937 gen; //Standard mersenne_twister_engine seeded with rd()
	static std::uniform_int_distribution<> dis; //Ensures that the number generated is between 1 and 6
};