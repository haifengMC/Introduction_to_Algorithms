#include "hList.h"
#pragma once

template<typename Ty>
class hListNode
{
	Ty* _data = NULL;
	hListNode<Ty>* _other[2] = {};
public:
	hListNode<Ty>*& next(bool rFlag) { return _other[rFlag ? 0 : 1]; }
	hListNode<Ty>*& prev(bool rFlag) { return _other[rFlag ? 1 : 0]; }
};

template<typename Ty>
class hListIterator
{
	hListNode<Ty>* _node;
};

template<typename Ty, typename alloc>
hList<Ty, alloc>::~hList()
{
}

template<typename Ty, typename alloc>
template <class... Arg>
inline bool hList<Ty, alloc>::emplaceBack(Arg&&... param)
{
	_Node* pNode = _AllocNode::alloc();
	if (!pNode)
		return false;

	_AllocNode::create(pNode);
	pNode->_data = _Alloc::alloc();
	if (!pNode->_data)
	{
		_AllocNode::destroy(pNode);
		_AllocNode::dealloc(pNode);
		return false;
	}
	_Alloc::create(pNode->_data, param);

	pNode->prev(_rvFlag) = _node.prev(_rvFlag);
	pNode->next(_rvFlag) = &_node;
	_node.prev(_rvFlag)->next(_rvFlag) = pNode;
	_node.prev(_rvFlag) = pNode;

	return true;
}
