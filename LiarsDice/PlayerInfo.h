#pragma once
#include <string>
#include <vector>
using namespace std;

class Player
{
private:
	string m_name;
public:

	void SetName(const string& name)
	{
		m_name = name;
	}

	const string& GetName() const
	{
		return m_name;
	}

	vector<string> generateVectorNames(int& numPlayers);
	void print(int numPlayers, vector<string>& playerVector);
	void playerOptions(string player);
	void GetPlayerInput(string& playerInput);
};