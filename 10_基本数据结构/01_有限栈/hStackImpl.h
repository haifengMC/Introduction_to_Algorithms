#pragma once

template<typename Ty, size_t N>
size_t hStack<Ty, N>::push(const Ty& val)
{
	assert(_top < N);
	_data[_top] = val;

	return ++_top;

}

template<typename Ty, size_t N>
size_t hStack<Ty, N>::pop()
{
	assert(_top);

	return --_top;
}