#pragma once

template<typename Ty, size_t N>
class hDoubleStack
{
	using _Size_Ty = std::ratio<sizeof(Ty), 1>;
	using _Size_N = std::ratio_add<std::ratio<N, 1>, std::ratio<1, 1>>;
	using _Size = std::ratio_multiply<_Size_Ty, _Size_N>;

	size_t _top1 = 0;
	size_t _top2 = N;
	Ty* _data = (Ty*)malloc(_Size::num);
public:
	bool empty1() const { return !_top1; }
	size_t push1(const Ty& t);
	size_t pop1();

	Ty* begin1() { return _data; }
	Ty* end1() { return _data + _top1; }

	bool empty2() const { return _top2 >= N; }
	size_t push2(const Ty& t);
	size_t pop2();

	Ty* begin2() { return _data + N; }
	Ty* end2() { return _data + _top2; }

	~hDoubleStack() { free(_data); }
};

#include "hDoubleStackImpl.h"