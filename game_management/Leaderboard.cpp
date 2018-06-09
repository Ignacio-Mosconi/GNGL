#include "Leaderboard.h"

namespace gn
{
	Leaderboard::Leaderboard()
	{
		_scores = new list<scoreReg>();
		_amount = DEFAULT_AMOUNT;
	}

	Leaderboard::Leaderboard(int amount)
	{
		_scores = new list<scoreReg>();
		_amount = amount;
	}

	Leaderboard::~Leaderboard()
	{
		if (_scores)
			delete _scores;
	}

	bool Leaderboard::addScore(scoreReg newScore)
	{
		bool addedScore = false;

		if (_scores->empty())
		{
			_scores->push_front(newScore);
			addedScore = true;
		}
		else
			for (list<scoreReg>::iterator it = _scores->begin(); it != _scores->end(); it++)
			{
				if (it->score < newScore.score)
				{
					_scores->insert(it, newScore);
					if (_scores->size() > _amount)
						_scores->pop_back();
					addedScore = true;;
				}
			}
		return addedScore;
	}

	scoreReg Leaderboard::getHighestScore()
	{
		return _scores->front();
	}
}