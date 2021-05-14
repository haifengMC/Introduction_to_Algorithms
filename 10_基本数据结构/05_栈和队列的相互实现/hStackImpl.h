#pragma once

template<typename Ty, size_t N>
Ty& hStack<Ty, N>::at(size_t id)
{
	assert(id < _top);
	return _data[(id) % _Size_N::num];
}

template<typename Ty, size_t N>
size_t hStack<Ty, N>::push(const Ty& val)
{
	assert(_top < N);
	_data[_top] = val;

	return ++_top;

}

template<typename Ty, size_t N>
Ty hStack<Ty, N>::pop()
{
	assert(_top);
	Ty tmp = _data[--_top];
	return tmp;
}