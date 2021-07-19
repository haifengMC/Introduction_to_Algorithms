#include <string>
#include <iostream>

using namespace std;

uint8_t maxEleId = 0;

struct HashTree
{
	static uint8_t _eleNum[];
	uint8_t _eleId = 0;
	size_t _data = 0;
	HashTree** _pNextArr = NULL;

	HashTree(uint8_t eleId = 0)
	{
		_eleId = eleId;
		_pNextArr = new HashTree * [_eleNum[_eleId]]();
	}
	~HashTree()
	{
		delete[] _pNextArr;
	}

	void insert(size_t i)
	{
		if (_data == i)
			return;

		HashTree*& pNext = _pNextArr[i % _eleNum[_eleId]];
		if (pNext)
			pNext->insert(i);
		else
		{
			if (maxEleId < _eleId + 1)
			{
				maxEleId = _eleId + 1;
				cout << "[" << (size_t)maxEleId << "]" << _data;
			}
			pNext = new HashTree(_eleId + 1);
			pNext->_data = i;
		}
	}

	ostream& fillDebug(ostream& os, uint8_t idx = 0) const
	{
		os << (size_t)_eleId << "_" << _data << ",{";
		bool first = true;
		for (uint8_t i = 0; i < _eleNum[_eleId]; ++i)
		{
			if (first) first = false;
			else os << ",";

			HashTree* pNext = _pNextArr[i];
			if (pNext)
			{
				os << endl;
				cout << string(idx + 1, '\t') << "[" << (size_t)i << "]";
				pNext->fillDebug(os, idx + 1);
			}
			else
				os << "[" << (size_t)i << "]" << "NULL";
		}
		return os << "}";
	}
};
uint8_t HashTree::_eleNum[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71 };

int main()
{
	HashTree tree;
	for (int i = 1; i < 1000; ++i)
		tree.insert(i);

	tree.fillDebug(cout) << endl;
	size_t i = 0;
	while (cin >> i)
	{
		tree.insert(i);
		tree.fillDebug(cout) << endl;
	}

	return 0;
}