#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <iostream>
#include <fstream>
#include <list>
#include "Structures.h"
#define DEFAULT_SIZE 10
#define MAX_SIZE 1000

using namespace std;

namespace gn
{
	class Leaderboard
	{
	private:
		list<scoreReg>* _scores;
		int _size;

	public:
		Leaderboard(const int& size = DEFAULT_SIZE);
		~Leaderboard();

		bool addScore(const scoreReg& score);
		bool clearLeaderboard();
		bool resizeLeaderboard(const int& newSize);

		scoreReg getTopScore() const;
		scoreReg retrieveScore(const int& ranking) const;
		string getBestPlayer() const;
		int getBestScore() const;
		int getCurrentSize() const;
	};
}

#endif
