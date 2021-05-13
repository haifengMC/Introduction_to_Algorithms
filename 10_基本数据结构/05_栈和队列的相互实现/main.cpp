/*
P131
10.1-6˵�����������ջʵ��һ�����У���������ض��в���������ʱ�䡣
10.1-7˵���������������ʵ��һ��ջ�����������ջ����������ʱ�䡣

����ʱ��ΪO(1)
ɾ��ʱ��ΪO(n)
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