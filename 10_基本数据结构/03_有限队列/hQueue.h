#pragma once

template<typename Ty, size_t N>
class hQueueIterator;
template<typename Ty, size_t N>
class hQueue
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

#include "hQueueImpl.h"