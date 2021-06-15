#pragma once

template<typename Ty>
class hStdAlloc;
template<typename Ty>
class hListIterator;
template<typename Ty>
class hListNode;
template<typename Ty, typename Alloc = hStdAlloc<Ty>>
class hList
{
	using _Iterator = hListIterator<Ty>;
	using _Node = hListNode<Ty>;
	using _AllocTy = typename std::_Replace_first_parameter<Ty, Alloc>::type;
	using _AllocNode = typename std::_Replace_first_parameter<_Node, Alloc>::type;

	bool _rvFlag = false;
	size_t _num = 0;
	_Node _node;
public:
	using Iter = _Iterator;

	hList();
	~hList();

	bool empty() const { return !size(); }
	size_t size() const { return _num; }

	void reverse() { _rvFlag = !_rvFlag; }

	bool pushBack(const Ty& value) { return emplaceBack(value); }
	bool pushBack(Ty&& value) { return emplaceBack(std::move(value)); }
	template <class... Arg>
	bool emplaceBack(Arg&&... param);

	Iter begin();
	Iter end();
};

#include "hAllocator.h"
#include "hListImpl.h"
