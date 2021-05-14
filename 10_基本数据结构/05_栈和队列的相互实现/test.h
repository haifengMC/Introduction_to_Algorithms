#pragma once
#include "hStack.h"
#include "hQueue.h"

template<typename Ty, size_t N>
class TestStack
{
	size_t _id = 0;
	hQueue<Ty, N> que[2];
public:
	bool empty() const { return que[_id].empty(); }
	size_t size() const { return que[_id].size(); }
	size_t push(const Ty& t) { return que[_id].enqueue(t); }
	Ty pop()
	{
		assert(!empty());

		size_t oldId = _id;
		_id = (_id + 1) % 2;
		while (que[oldId].size() > 1)
			que[_id].enqueue(que[oldId].dequeue());

		return que[oldId].dequeue();
	}

	Ty& operator[](size_t id) { return que[_id].at(id); }
}; 

#if 0

template<typename Ty, size_t N>
class TestQueue
{
	size_t _head = 0;
	size_t _tail = 0;
	Ty* _data = NULL;
public:
	using _Size_Ty = std::ratio<sizeof(Ty), 1>;
	using _Size_N = std::ratio_add<std::ratio<N, 1>, std::ratio<1, 1>>;
	using _Size = std::ratio_multiply<_Size_Ty, _Size_N>;
	using _Iterator = hQueueIterator<Ty, N>;

	using Iterator = _Iterator;
	hQueue();
	~hQueue() { free(_data); }

	bool empty() const { return _head == _tail; }
	size_t size() const;
	Ty& at(size_t id);
	size_t enqueue(const Ty& t);
	size_t dequeue();

	Iterator begin();
	Iterator end();

	Ty& operator[](size_t id) { return at(id); }
};
#endif