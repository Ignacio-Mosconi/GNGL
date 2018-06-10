#include "Leaderboard.h"

namespace gn
{
	Leaderboard::Leaderboard(const int& size)
	{
		_scores = new list<scoreReg>();
		_size = (size > 0 && size < MAX_SIZE) ? size : DEFAULT_SIZE;
	}

	Leaderboard::~Leaderboard()
	{
		if (_scores)
			delete _scores;
	}

	bool Leaderboard::addScore(const scoreReg& newScore)
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

	bool Leaderboard::resizeLeaderboard(const int& newSize)
	{
		if (newSize > 0 && newSize < MAX_SIZE)
		{
			if (_size > newSize)
				for (int i = 0; i < _size - newSize; i++)
					_scores->pop_back();
			_size = newSize;
			return true;
		}
		else
			return false;
	}

	scoreReg Leaderboard::getTopScore() const
	{
		return _scores->front();
	}

	string Leaderboard::getBestPlayer() const
	{
		return _scores->front().name;
	}

	int Leaderboard::getBestScore() const
	{
		return _scores->front().score;
	}
	
	scoreReg Leaderboard::retrieveScore(const int& ranking) const
	{	
		int i = 1;
		list<scoreReg>::iterator it;

		for (it = _scores->begin(); i <= ranking && it != _scores->end(); it++)
		{
			if (i == ranking)
				break;
			else
				i++;
		}

		return *it;
	}

	int Leaderboard::getCurrentSize() const
	{
		return _scores->size();
	}
}