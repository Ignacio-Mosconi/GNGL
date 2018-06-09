#include "Leaderboard.h"

namespace gn
{
	Leaderboard::Leaderboard()
	{
		_scores = new list<scoreReg>();
		_size = DEFAULT_SIZE;
	}

	Leaderboard::Leaderboard(int size)
	{
		_scores = new list<scoreReg>();
		_size = (size > 0 && size < MAX_SIZE) ? size : DEFAULT_SIZE;
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
					if (_scores->size() > _size)
						_scores->pop_back();
					addedScore = true;
					break;
				}
			}
		
		return addedScore;
	}

	bool Leaderboard::clearLeaderboard()
	{
		_scores->clear();

		return _scores->empty();
	}

	bool Leaderboard::resizeLeaderboard(int newSize)
	{
		if (newSize > 0 && newSize < MAX_SIZE)
		{
			_size = newSize;
			return true;
		}
		else
			return false;
	}

	scoreReg Leaderboard::getTopScore()
	{
		return _scores->front();
	}

	string Leaderboard::getBestPlayer()
	{
		return _scores->front().name;
	}

	int Leaderboard::getBestScore()
	{
		return _scores->front().score;
	}

}