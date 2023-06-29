#include "PlayerInfo.h"
#include <vector>
#include <iostream>
#include <string>

Player player;
string m_name;
int playerPosition = 1;

// Function to generate a vector of player names based on the number of players
vector<string> Player::generateVectorNames(int& numPlayers)
{
	vector<string> vectorNames;
	for (int i = 0; i < numPlayers; i++)
	{	
		cout << "Enter name for player #" << playerPosition << ":" << endl;
		cin >> m_name;
		player.SetName(m_name);
		vectorNames.push_back(player.GetName());
		playerPosition++;
	}
	playerPosition = 1;
	return vectorNames;
}
// Function to print the player names
void Player::print(int numPlayers, vector<string>& playerVector)
{
	for (int i = 0; i < numPlayers; i++)
	{
		cout << "Player #" << playerPosition << " " << playerVector[i] <<endl;
		playerPosition++;
	}
	playerPosition = 1;
}
// Function to get player input from the user
void Player::GetPlayerInput(string& playerInput) 
{
	cin >> playerInput;
}

// Function to display player options
void Player::playerOptions(string player) {
	cout << player << " choose your move" << endl;
	cout << "1: Look at your Dice" << endl;
	cout << "2: Wager" << endl;
	cout << "3: Accuse previous player of being a liar." << endl;
	cout << "4: Quit" << endl;
}
