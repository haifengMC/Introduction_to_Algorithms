#include "hList.h"
#pragma once

template<typename Ty>
class hListNode
{
	template<typename Ty, typename alloc>
	friend class  hList;

	Ty* _data = NULL;
	hListNode<Ty>* _prev = NULL;
	hListNode<Ty>* _next = NULL;
public:
	
};

template<typename Ty, typename alloc>
inline hList<Ty, alloc>::hList()
{
	_nil._prev = &_nil;
	_nil._next = &_nil;
}

template<typename Ty, typename alloc>
inline hList<Ty, alloc>::~hList()
{
}

template<typename Ty, typename alloc>
bool hList<Ty, alloc>::empty() const
{
	return &_nil == _nil._next;
}

template<typename Ty, typename alloc>
inline void hList<Ty, alloc>::pushBack(const Ty& value)
{
	hListNode<Ty>* pNode = _alloc.alloc();
	_alloc.create(pNode, value);
	pNode->_data = _alloc.alloc();
}

template<typename Ty, typename alloc>
inline void hList<Ty, alloc>::pushBack(Ty&& value)
{

}
