/*
P131 
10.1-1仿照图10-1，画图表示依次执行操作PUSH(S，4)、PUSHS，1)、PUSH(S，3)、
POP(S)、PUSH(S，8)和POP(S)每一步的结果，栈S初始为空，存储于数组S[1..6]中。
*/

#include <ratio>
#include <iostream>
#include <assert.h>
#include "hStack.h"

using namespace std;

int main()
{
	hStack<int, 6> s;
	auto pS = [&]()
	{
		cout << "{";
		bool first = true;
		for (auto i : s)
		{
			if (first) first = false;
			else cout << ", ";

			cout << i;
		}
		cout << "}" << endl;
	};

	cout << s.push(4) << " ";
	pS();
	cout << s.push(1) << " ";
	pS();
	cout << s.push(3) << " ";
	pS();
	cout << s.pop() << " ";
	pS();
	cout << s.push(8) << " ";
	pS();
	cout << s.pop() << " ";
	pS();

	return 0;
}