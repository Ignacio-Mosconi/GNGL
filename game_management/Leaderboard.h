#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include <list>
#include "Structures.h"
#define DEFAULT_AMOUNT 10
using namespace std;

namespace gn
{
	class Leaderboard
	{
	private:
		list<scoreReg>* _scores;
		int _amount;

	public:
		Leaderboard();
		Leaderboard(int amount);
		~Leaderboard();

		bool addScore(scoreReg score);
		scoreReg getHighestScore();
	};
}

#endif
