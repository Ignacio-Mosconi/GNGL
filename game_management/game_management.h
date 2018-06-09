#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

#include "Structures.h"
#include "Leaderboard.h"

namespace gn
{
	scoreReg createScore(string name, int score);
	Leaderboard* createLeaderboard(int size);
	void destroyLeaderboard(Leaderboard* leaderboard);
}

#endif
