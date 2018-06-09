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
		list<Score>* _scores;
		int _amount;

	public:
		Leaderboard();
		Leaderboard(int amount);
		~Leaderboard();

		bool addScore(Score score);
		Score getHighestScore();
	};
}

#endif
