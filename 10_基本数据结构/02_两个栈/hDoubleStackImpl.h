#pragma once

template<typename Ty, size_t N>
size_t hDoubleStack<Ty, N>::push1(const Ty& val)
{
	assert(_top1 < _top2);
	_data[_top1] = val;
	return ++_top1;

}

template<typename Ty, size_t N>
size_t hDoubleStack<Ty, N>::pop1()
{
	assert(_top1);
	return --_top1;
}

template<typename Ty, size_t N>
size_t hDoubleStack<Ty, N>::push2(const Ty& val)
{
	assert(_top1 < _top2);
	_data[_top2] = val;
	return N - --_top2;

}

template<typename Ty, size_t N>
size_t hDoubleStack<Ty, N>::pop2()
{
	assert(_top2 < N);
	return N - ++_top2;
}