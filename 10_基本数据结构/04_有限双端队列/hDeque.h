#pragma once

template<typename Ty, size_t N>
class hDeque
{
	size_t _head = 0;
	size_t _tail = 0;
	Ty* _data = NULL;

	using _Size_Ty = std::ratio<sizeof(Ty), 1>;
	using _Size_N = std::ratio_add<std::ratio<N, 1>, std::ratio<1, 1>>;
	using _Size = std::ratio_multiply<_Size_Ty, _Size_N>;
public:
	hDeque();
	~hDeque() { free(_data); }

	bool empty() const { return _head == _tail; }
	size_t size() const;
	Ty& at(size_t id);
	size_t pushFront(const Ty& t);
	size_t popFront();
	size_t pushBack(const Ty& t);
	size_t popBack();

	Ty& operator[](size_t id) { return at(id); }
private:
	size_t getPre(size_t id);
	size_t getNext(size_t id);
};

#include "hDequeImpl.h"