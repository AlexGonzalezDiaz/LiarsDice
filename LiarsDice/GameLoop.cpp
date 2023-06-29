/*
* Name: Alex Gonzalez Diaz
* Project: Liars Dice
* IT 312
*/


#include "Dice.h"
#include "PlayerInfo.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;
Player m_player;

int main() {
	int numPlayers = 0;
	int m = 5, pos = 1, guessNum = 0, typeDice = 0, wager[2] = { 0,0 };
	int ptr1 = *(wager);

	// Displaying the rules from the rules.txt file
	string tp;
	fstream file;
	file.open("liarsDiceRules.txt", ios::in);
	if (file.is_open()) {
		string tp;
		while (getline(file, tp)) {
			cout << tp << "\n";
		}
	}
	file.close();

	// Asking the player to add more than one player
	cout << "*************" << endl;
	while (numPlayers <= 1) {
		cout << "How many players" << endl;
		cin >> numPlayers;
		if (numPlayers <= 1) {
			cout << "There has to be more than 1 player, find someone to play with!" << endl;
		}
	}

	// After getting all the names and number of players,
	// the names will be saved in a vector,
	// and each player will be assigned 5 rolled dice, stored in a 2D vector
	vector<string> names(numPlayers);
	vector<vector<int>> hands(numPlayers, vector<int>(m));
	hands = generateVectorDice(numPlayers, vector<int>(m));
	names = m_player.generateVectorNames(numPlayers);

	// Entering the game loop, I made these variables to move in and out of the nested do while loops.
	// The outermost do-while loop controls the moves of each individual player until a certain condition is met,
    // and then switches to the next player
	bool loop = true;
	bool innerLoop = true;
	int j = 0;
	
	
	 do{
		names[j];
		string playerInput;
		do {
			m_player.playerOptions(names[j]);
			m_player.GetPlayerInput(playerInput);

			if (playerInput.compare("1") == 0)
			{
				printSpecificHand(j, hands);
			}
			else if (playerInput.compare("2") == 0)
			{
				// Getting the wager from the player
				cout << "What is your wager?" << endl;
				cout << "How many dice?" << endl;
				cin >> wager[0];
				cout << "Which dice?" << endl;
				cin >> wager[1];
				innerLoop = false;
				if (ptr1 > *(wager)) {
					cout << "The first number must be greater than the one called.." << endl;
					innerLoop = true;
				}
				ptr1 = *(wager);
			}
			else if (playerInput.compare("3") == 0)
			{
				// Player claims that another player is a liar
				cout << names[j] << " Claims that your a liar!" << endl;
				guessNum = wager[0];
				typeDice = wager[1];
				cout << endl;
				cout << "The previous wager was " << wager[0] << ", " << wager[1]<< endl;
				cout << checkForWinner(numPlayers, guessNum, typeDice, hands);
				innerLoop = false;
			}
			else if (playerInput.compare("4") == 0)
			{	
				// Player chooses to exit the game
				cout << "Thanks for playing" << endl;
				innerLoop = false;
				loop = false;
			}
			else
			{
				cout << "I do not recognise that option, try again!" << endl << endl;
			}
			cout << endl;
		} while (innerLoop);

		// Incrementing to the next player and resetting the innerLoop to true if the counter is less than the array size
		if (j < names.size()-1) {
			j++;
			pos++;
			innerLoop = true;
		}
		// If j has reached the end of the array, everything is reset to display player one
		else {
			j = 0;
			pos = 1;
			innerLoop = true;
		}
		// Once someone claims somebody is a liar, a new game is prompted and new dice are rolled
		if (playerInput.compare("3") == 0) {
			cout << "New Game!" << endl;
			hands = generateVectorDice(numPlayers, vector<int>(m));
			j = 0;
			pos = 1;
			innerLoop = true;
		}

	 } while (loop);


	return 0;
}

