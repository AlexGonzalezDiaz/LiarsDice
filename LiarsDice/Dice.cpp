
#include "Dice.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <map>

/*
* Most of the methods concerning the dice and all the 2D vector handling is inside this class
* My biggest project was to return a 2D array and have the other methods help print out the elements inside the method.
* 
*/
using namespace std;

int dice()
{
		return rand() % 6 + 1;
}

vector<vector<int>> generateVectorBois(int numPlayers, vector<int>(m))
{
		srand((unsigned int)time(NULL));
		vector<vector<int> > diceRolls(numPlayers, vector<int>(m));
		vector<vector<int> > v(numPlayers, vector<int>(m));
		for (int i = 0; i < numPlayers; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				diceRolls[i][j] = dice();
				v[i][j] = diceRolls[i][j];
			}
		}
		return v;
}

void printDiceHands(int numPlayers, vector<vector<int>>& Hands)
{
	for (int i = 0; i < numPlayers; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << Hands[i][j] << " ";
			}
			cout << endl;
		}
	}

void printSpecificHand(int num, vector<vector<int>>& Hands)
{
	int input = num;
	cout << "Your dice hand is: ";
	for (int i = 0; i < 5; i++)
	{
		cout << Hands[input][i] << " ";
	}
	cout << "\n";
} 

string checkForWinner(int numPlayers, int guessNum , int typeDice, vector<vector<int>>& Hands)
{
	map<int, int> m;

	for (int i = 0; i < numPlayers; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m[Hands[i][j]]++;
		}
		cout << endl;
	}

	for (auto it : m) {
		if (it.first == typeDice) 
		{
			if (guessNum <= it.second)
			{
				cout << "Looks like they where telling the truth"<<endl;
				cout << it.second << " " << it.first <<"'s" << endl;
			}
			else
			{
				cout << " They are a LIAR and will spend eternity on this ship!" << endl;
				cout << it.second << " " << it.first << "'s" << endl;
			}
		}
	}
	return " ";
}








