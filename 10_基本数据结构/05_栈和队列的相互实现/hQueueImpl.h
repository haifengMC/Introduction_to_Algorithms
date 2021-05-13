#include "hQueue.h"
#pragma once

template<typename Ty, size_t N>
class hQueueIterator
{
	template<typename Ty, size_t N>
	friend class hQueue;

	hQueue<Ty, N>* _pQ = NULL;
	size_t _id = 0;
public:
	Ty& operator*();
	hQueueIterator& operator++();
	hQueueIterator operator++(int);
	bool operator==(const hQueueIterator& other);
	bool operator!=(const hQueueIterator& other) { return !(*this == other); }
};

template<typename Ty, size_t N>
hQueue<Ty, N>::hQueue()
{
	_data = (Ty* )malloc(_Size::num);
	memset(_data, 0, _Size::num);
}

template<typename Ty, size_t N>
size_t hQueue<Ty, N>::size() const
{
	if (_tail < _head)
		return _tail + _Size_N::num - _head;

	return _tail - _head;
}

template<typename Ty, size_t N>
Ty& hQueue<Ty, N>::at(size_t id)
{
	assert(id < size());
	return _data[(id + _head) % _Size_N::num];
}

template<typename Ty, size_t N>
size_t hQueue<Ty, N>::enqueue(const Ty& t)
{
	size_t tail = (_tail + 1) % _Size_N::num;
	assert(tail != _head);
	_data[_tail] = t;
	_tail = tail;
	return size();
}

template<typename Ty, size_t N>
Ty hQueue<Ty, N>::dequeue()
{
	assert(_head != _tail);
	Ty tmp = at(0);
	_head = (_head + 1) % _Size_N::num;
	return tmp;
}

template<typename Ty, size_t N>
typename hQueue<Ty, N>::Iterator hQueue<Ty, N>::begin()
{
	Iterator it;
	it._pQ = this;
	it._id = 0;
	return it;
}

template<typename Ty, size_t N>
typename hQueue<Ty, N>::Iterator hQueue<Ty, N>::end()
{
	Iterator it;
	it._pQ = this;
	it._id = size();
	return it;
}

template<typename Ty, size_t N>
Ty& hQueueIterator<Ty, N>::operator*()
{
	assert(_pQ);
	return _pQ->at(_id);
}

template<typename Ty, size_t N>
hQueueIterator<Ty, N>& hQueueIterator<Ty, N>::operator++()
{
	_id = (_id + 1) % hQueue<Ty, N>::_Size_N::num;
	return *this;
}

template<typename Ty, size_t N>
hQueueIterator<Ty, N> hQueueIterator<Ty, N>::operator++(int)
{
	hQueueIterator<Ty, N> it;
	it._pQ = _pQ;
	it._id = _id;
	_id = (_id + 1) % hQueue<Ty, N>::_Size_N::num;
	return it;
}

template<typename Ty, size_t N>
bool hQueueIterator<Ty, N>::operator==(const hQueueIterator<Ty, N>& other)
{
	assert(_pQ == other._pQ);
	return _id == other._id;
}
