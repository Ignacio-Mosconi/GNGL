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
}