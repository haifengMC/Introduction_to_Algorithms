/*
P131
10.1-2说明如何在一个数组A[1..n]中实现两个栈，使得当两个栈的元素个数之和不为n时，
两者都不会发生上溢。要求PUSH和 POP操作的运行时间为O1)。
*/

#include <ratio>
#include <iostream>
#include <assert.h>
#include "hDoubleStack.h"

using namespace std;

int main()
{
	hDoubleStack<int, 6> s;
	auto pS = [&]()
	{
		cout << "1:{";
		bool first = true;
		for (auto it1 = s.begin1(); it1 != s.end1(); ++it1)
		{
			if (first) first = false;
			else cout << ", ";

			cout << *it1;
		}
		cout << "} 2:{";
		first = true;
		for (auto it2 = s.begin2(); it2 != s.end2(); --it2)
		{
			if (first) first = false;
			else cout << ", ";

			cout << *it2;
		}
		cout << "}" << endl;
	};

	cout << s.push2(4) << " ";
	pS();
	cout << s.push2(1) << " ";
	pS();
	cout << s.push2(3) << " ";
	pS();
	cout << s.push1(4) << " ";
	pS();
	cout << s.push1(1) << " ";
	pS();
	cout << s.push1(3) << " ";
	pS();
	cout << s.pop1() << " ";
	pS();
	cout << s.push2(8) << " ";
	pS();
	cout << s.pop2() << " ";
	pS();

	return 0;
}
