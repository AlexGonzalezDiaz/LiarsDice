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

	//This part of the code is to display the rules from the rules.txt file
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

	//Here is where we ask the player to add more than one player,
	cout << "*************" << endl;
	while (numPlayers <= 1) {
		cout << "How many players" << endl;
		cin >> numPlayers;
		if (numPlayers <= 1) {
			cout << "There has to be more than 1 player, find someone to play with!" << endl;
		}
	}

	// After we get all the names and number of players,
	// The names will be saved in a vector.
	// Each player will be assigned 5 dice rolled already, these are stored in a 2D vector
	vector<string> names(numPlayers);
	vector<vector<int>> hands(numPlayers, vector<int>(m));

	// The biggest hurdle was to return a 2D vector from a method call.
	hands = generateVectorBois(numPlayers, vector<int>(m));
	names = m_player.generateVectorNames(numPlayers);

	//Entering the game loop, I made these variables to move in and out of the nested do while loops.
	bool loop = true;
	bool innerLoop = true;
	int j = 0;
	//The outermost do - while loop controls the moves of the individual player until a certain condition is met.
	//Then it will switch to the next player.
	
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

		//In the outside do-while loop, I increment to the next player and reset the innerLoop to true if the counter is less then the array size
		//This caused an error for me since it was hard to find a good way to switch in between a larger group than 2
		if (j < names.size()-1) {
			j++;
			pos++;
			innerLoop = true;
		}
		//If j has reached the end of the array, everything is reset to display player one.
		else {
			j = 0;
			pos = 1;
			innerLoop = true;
		}
		//Once someone claims somebody is a liar this will prompt for a new game and roll new dice.
		if (playerInput.compare("3") == 0) {
			cout << "New Game!" << endl;
			hands = generateVectorBois(numPlayers, vector<int>(m));
			j = 0;
			pos = 1;
			innerLoop = true;
		}

	 } while (loop);


	return 0;
}

