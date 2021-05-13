#pragma once

template<typename Ty, size_t N>
class hStack
{
	using _Size_Ty = std::ratio<sizeof(Ty), 1>;
	using _Size_N = std::ratio<N, 1>;
	using _Size = std::ratio_multiply<_Size_Ty, _Size_N>;

	size_t _top = 0;
	Ty* _data = (Ty*)malloc(_Size::num);
public:
	bool empty() const { return !_top; }
	size_t push(const Ty& t);
	size_t pop();

	Ty* begin() { return _data; }
	Ty* end() { return _data + _top; }

	~hStack() { free(_data); }
};

#include "hStackImpl.h"