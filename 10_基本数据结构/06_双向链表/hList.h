#pragma once

class hAllocator;

template<typename Ty>
class hListIterator;
template<typename Ty>
class hListNode;
template<typename Ty, typename alloc = hAllocator>
class hList
{
	//using _Iterator = hListIterator<Ty>;
	size_t _num;
	hListNode _nil;
public:
	//using Iterator = _Iterator;

	hList();
	~hList();

	bool empty() const;
	size_t size() const { return _num; }

	void pushBack(const Ty& value);
	void pushBack(Ty&& value);
};

#include "hAllocator.h"
#include "hListImpl.h"
