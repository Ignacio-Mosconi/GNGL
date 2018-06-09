#ifndef LEADERBOARD_H
#define LEADERBOARD_H

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
		Leaderboard();
		Leaderboard(int size);
		~Leaderboard();

		bool addScore(scoreReg score);
		bool clearLeaderboard();
		bool resizeLeaderboard(int newSize);

		scoreReg getTopScore();
		string getBestPlayer();
		int getBestScore();
	};
}

#endif
