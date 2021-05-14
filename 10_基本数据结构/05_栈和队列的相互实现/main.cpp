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

#define OPTS(func, ...) \
	cout << #func << " "#####__VA_ARGS__##":" << s.func(##__VA_ARGS__);pS()
#define OPTQ(func, ...) \
	cout << #func << " "#####__VA_ARGS__##":" << q.func(##__VA_ARGS__);pQ()


int main()
{
	TestStack<int, 3> s;
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

	OPTS(push, 3);
	OPTS(push, 1);
	OPTS(push, 4);
	OPTS(pop);
	OPTS(push, 8);
	OPTS(pop);



	TestQueue<int, 3> q;
	auto pQ = [&]()
	{
		cout << "{";
		bool first = true;
		for (size_t i = 0; i < q.size(); i++)
		{
			if (first) first = false;
			else cout << ", ";

			cout << q[i];
		}
		cout << "}" << endl;
	};

	OPTQ(push, 3);
	OPTQ(push, 1);
	OPTQ(push, 4);
	OPTQ(pop);
	OPTQ(push, 8);
	OPTQ(pop);

	return 0;
}