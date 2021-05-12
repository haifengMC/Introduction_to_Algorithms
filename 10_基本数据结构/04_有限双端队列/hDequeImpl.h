#include "hDeque.h"
#pragma once

template<typename Ty, size_t N>
hDeque<Ty, N>::hDeque()
{
	_data = (Ty*)malloc(_Size::num);
	memset(_data, 0, _Size::num);
}

template<typename Ty, size_t N>
size_t hDeque<Ty, N>::size() const
{
	if (_tail < _head)
		return _tail + _Size_N::num - _head;

	return _tail - _head;
}

template<typename Ty, size_t N>
Ty& hDeque<Ty, N>::at(size_t id)
{
	assert(id < size());
	return _data[(id + _head) % _Size_N::num];
}

template<typename Ty, size_t N>
size_t hDeque<Ty, N>::pushFront(const Ty& t)
{
	size_t head = getPre(_head);
	assert(_tail != head);
	_head = head;
	_data[_head] = t;
	return size();
}

template<typename Ty, size_t N>
size_t hDeque<Ty, N>::popFront()
{
	assert(_head != _tail);
	_head = getNext(_head);
	return size();
}

template<typename Ty, size_t N>
size_t hDeque<Ty, N>::pushBack(const Ty& t)
{
	size_t tail = getNext(_tail);
	assert(tail != _head);
	_data[_tail] = t;
	_tail = tail;
	return size();
}

template<typename Ty, size_t N>
size_t hDeque<Ty, N>::popBack()
{
	assert(_head != _tail);
	_tail = getPre(_tail);
	return size();
}

template<typename Ty, size_t N>
inline size_t hDeque<Ty, N>::getPre(size_t id)
{
	if (!id)
		return N;

	return id - 1;
}

template<typename Ty, size_t N>
inline size_t hDeque<Ty, N>::getNext(size_t id)
{
	if (id >= N)
		return 0;

	return id + 1;
}
