#include "hList.h"
#pragma once

template<typename Ty>
class hListNode
{
	template<typename Ty, typename Alloc>
	friend class hList;
	template<typename Ty>
	friend class hListIterator;

	Ty* _data = NULL;
	hListNode<Ty>* _other[2] = {};
public:
	hListNode<Ty>*& next(bool rFlag) { return _other[rFlag ? 0 : 1]; }
	hListNode<Ty>*& prev(bool rFlag) { return _other[rFlag ? 1 : 0]; }
};

template<typename Ty>
class hListIterator
{
	template<typename Ty, typename Alloc>
	friend class hList;

	bool _rvFlag = false;
	hListNode<Ty>* _node = NULL;
public:
	Ty& operator*();
	hListIterator& operator++();
	hListIterator operator++(int);
	bool operator==(const hListIterator& other);
	bool operator!=(const hListIterator& other) { return !(*this == other); }
};

template<typename Ty, typename Alloc>
inline hList<Ty, Alloc>::hList()
{
	_node._other[0] = &_node;
	_node._other[1] = &_node;
}

template<typename Ty, typename Alloc>
hList<Ty, Alloc>::~hList()
{
}

template<typename Ty, typename Alloc>
typename hList<Ty, Alloc>::Iter hList<Ty, Alloc>::begin()
{
	Iter it;
	it._rvFlag = _rvFlag;
	it._node = _node.next(_rvFlag);
	return it;
}

template<typename Ty, typename Alloc>
typename hList<Ty, Alloc>::Iter hList<Ty, Alloc>::end()
{
	Iter it;
	it._node = &_node;
	return it;
}

template<typename Ty, typename Alloc>
template <class... Arg>
inline bool hList<Ty, Alloc>::emplaceBack(Arg&&... param)
{
	_Node* pNode = _AllocNode::alloc();
	if (!pNode)
		return false;

	_AllocNode::create(pNode);
	pNode->_data = _AllocTy::alloc();
	if (!pNode->_data)
	{
		_AllocNode::destroy(pNode);
		_AllocNode::dealloc(pNode);
		return false;
	}
	_AllocTy::create(pNode->_data, param...);

	pNode->prev(_rvFlag) = _node.prev(_rvFlag);
	pNode->next(_rvFlag) = &_node;
	_node.prev(_rvFlag)->next(_rvFlag) = pNode;
	_node.prev(_rvFlag) = pNode;

	return true;
}

template<typename Ty>
Ty& hListIterator<Ty>::operator*()
{
	assert(_node);
	assert(_node->_data);
	return *_node->_data;
}

template<typename Ty>
hListIterator<Ty>& hListIterator<Ty>::operator++()
{
	assert(_node);
	assert(_node->_data);
	_node = _node->next(_rvFlag);
	return *this;
}

template<typename Ty>
hListIterator<Ty> hListIterator<Ty>::operator++(int)
{
	assert(_node);
	assert(_node->_data);
	hListIterator<Ty> it;
	it._rvFlag = _rvFlag;
	it._node = _node;
	_node = _node->next(_rvFlag);
	return it;
}

template<typename Ty>
bool hListIterator<Ty>::operator==(const hListIterator<Ty>& other)
{
	return _node == other._node;
}
