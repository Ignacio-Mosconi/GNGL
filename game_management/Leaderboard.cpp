#include "Leaderboard.h"

namespace gn
{
	Leaderboard::Leaderboard()
	{
		_scores = new list<Score>();
		_amount = DEFAULT_AMOUNT;
	}

	Leaderboard::Leaderboard(int amount)
	{
		_scores = new list<Score>();
		_amount = amount;
	}

	Leaderboard::~Leaderboard()
	{
		if (_scores)
			delete _scores;
	}

	bool Leaderboard::addScore(Score score)
	{
		bool addedScore = false;

		if (_scores->empty())
		{
			_scores->push_front(score);
			addedScore = true;
		}
		else
			for (list<Score>::iterator it = _scores->begin(); it != _scores->end(); it++)
			{
				if (it->score < score.score)
				{
					_scores->insert(it, score);
					if (_scores->size() > _amount)
						_scores->pop_back();
					addedScore = true;;
				}
			}
		return addedScore;
	}

	Score Leaderboard::getHighestScore()
	{
		return _scores->front();
	}
}