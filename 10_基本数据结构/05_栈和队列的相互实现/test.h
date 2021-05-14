#pragma once
#include "hStack.h"
#include "hQueue.h"

template<typename Ty, size_t N>
class TestStack
{
	size_t _id = 0;
	hQueue<Ty, N> _que[2];
public:
	bool empty() const { return _que[_id].empty(); }
	size_t size() const { return _que[_id].size(); }
	size_t push(const Ty& t) { return _que[_id].enqueue(t); }
	Ty pop()
	{
		assert(!empty());

		size_t oldId = _id;
		_id = (_id + 1) % 2;
		while (_que[oldId].size() > 1)
			_que[_id].enqueue(_que[oldId].dequeue());

		return _que[oldId].dequeue();
	}

	Ty& operator[](size_t id) { return _que[_id].at(id); }
}; 


template<typename Ty, size_t N>
class TestQueue
{
	size_t _id = 0;
	hStack<Ty, N> _sta[2];
public:
	bool empty() const { return _sta[_id].empty(); }
	size_t size() const { return _sta[_id].size(); }
	size_t push(const Ty& t) { return _sta[_id].push(t); }
	Ty pop()
	{
		assert(!empty());

		size_t oldId = _id;
		_id = (_id + 1) % 2;
		while (_sta[oldId].size() > 1)
			_sta[_id].push(_sta[oldId].pop());

		return _sta[oldId].pop();
	}

	Ty& operator[](size_t id) { return _sta[_id].at(id); }
};
