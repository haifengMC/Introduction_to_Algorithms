/*
P131
10.1-5栈插人和删除元素只能在同一端进行，队列的插人操作和删除操作分别在两端进行，
与它们不同的，有一种双端队列(deque)，其插入和删除操作都可以在两端进行。写出4个
时间均为O(1)的过程，分别实现在双端队列的两端插人和删除元素的操作，该队列是用一个
数组实现的。

*/

#include <ratio>
#include <iostream>
#include <assert.h>
#include "hDeque.h"

using namespace std;

#define _OPT_STRING(x) #x
#define OPT(func, ...) \
	cout << #func << " "#####__VA_ARGS__##":" << d.func(##__VA_ARGS__);pD()

int main()
{
	hDeque<int, 3> d;
	auto pD = [&]()
	{
		cout << "{";
		bool first = true;
		for (size_t i = 0; i < d.size(); i++)
		{
			if (first) first = false;
			else cout << ", ";

			cout << d[i];
		}
		cout << "}" << endl;
	};
	OPT(pushBack, 3);
	OPT(pushBack, 1);
	OPT(pushBack, 4);
	OPT(popFront);
	OPT(pushFront, 8);
	OPT(popBack);
	OPT(popFront);
	return 0;
}