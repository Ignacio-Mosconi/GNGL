#include "game_management.h"

namespace gn
{
	scoreReg createScore(string name, int score)
	{
		scoreReg newScore;

		newScore.name = name;
		newScore.score = score;

		return newScore;
	}

	Leaderboard* createLeaderboard(int size = DEFAULT_SIZE)
	{
		Leaderboard* leaderboard = new Leaderboard(size);
		return leaderboard;
	}

	void destroyLeaderboard(Leaderboard* leaderboard)
	{
		delete leaderboard;
	}
}