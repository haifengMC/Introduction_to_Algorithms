/*
P131
10.1-6说明如何用两个栈实现一个队列，并分析相关队列操作的运行时间。
10.1-7说明如何用两个队列实现一个栈，并分析相关栈操作的运行时间。

插入时间为O(1)
删除时间为O(n)
*/

#include <ratio>
#include <iostream>
#include <assert.h>
#include "test.h"

using namespace std;

#define OPT(func, ...) \
	cout << #func << " "#####__VA_ARGS__##":" << s.func(##__VA_ARGS__);pS()


int main()
{
	TestStack<int, 6> s;
	auto pS = [&]()
	{
		cout << "{";
		bool first = true;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (first) first = false;
			else cout << ", ";

			cout << s[i];
		}
		cout << "}" << endl;
	};

	OPT(push, 3);
	OPT(push, 1);
	OPT(push, 4);
	OPT(pop);
	OPT(push, 8);
	OPT(pop);

	return 0;
}