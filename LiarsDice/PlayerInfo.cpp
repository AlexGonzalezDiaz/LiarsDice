#include "PlayerInfo.h"
#include <vector>
#include <iostream>
#include <string>

Player player;
string m_name;
int playerPosition = 1;

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

void Player::print(int numPlayers, vector<string>& playerVector)
{
	for (int i = 0; i < numPlayers; i++)
	{
		cout << "Player #" << playerPosition << " " << playerVector[i] <<endl;
		playerPosition++;
	}
	playerPosition = 1;
}

void Player::GetPlayerInput(string& playerInput) 
{
	cin >> playerInput;
}

void Player::playerOptions(string player) {
	cout << player << " choose your move" << endl;
	cout << "1: Look at your Dice" << endl;
	cout << "2: Wager" << endl;
	cout << "3: Accuse previous player of being a liar." << endl;
	cout << "4: Quit" << endl;
}
