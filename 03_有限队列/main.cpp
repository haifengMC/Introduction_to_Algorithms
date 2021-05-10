/*
P131
10.1-3仿照图10-2，画图表示依次执行操作ENQUEUE(Q，4)、ENQUEUE(Q，1)、
ENQUEUE(Q，3)、DEQUEUE(Q)、ENQUEUE(Q，8)和 DEQUEUE(Q)每一步的结果,
队列初始为空，存储于数组Q[1..6]中。
*/

#include <ratio>
#include <iostream>
#include <assert.h>
#include "hQueue.h"

using namespace std;

int main()
{
	hQueue<int, 3> q;
	auto pQ = [&]()
	{
		cout << "{";
		bool first = true;
		for (auto i : q)
		{
			if (first) first = false;
			else cout << ", ";

			cout << i;
		}
		cout << "}" << endl;
	};

	pQ();
	cout << q.enqueue(4);
	pQ();
	cout << q.enqueue(1);
	pQ();
	cout << q.enqueue(3);
	pQ();
	cout << q.dequeue();
	pQ();
	cout << q.enqueue(8);
	pQ();
	cout << q.dequeue();
	pQ();

	return 0;
}

