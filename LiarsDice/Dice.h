#pragma once
#include "PlayerInfo.h"
#include "GameLoop.h"
#include <vector>
#include <unordered_map>

	int dice();
	vector<vector<int>> generateVectorBois(int numPlayers, vector<int>(m));
	void printDiceHands(int numPlayers, vector<vector<int>>& Hands);	
	void printSpecificHand(int num, vector<vector<int>>& Hands);
	string checkForWinner(int numPlayers, int guessNum, int typeDice, vector<vector<int>>& Hands);
	
