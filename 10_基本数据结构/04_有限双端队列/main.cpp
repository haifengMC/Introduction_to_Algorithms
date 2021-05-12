/*
P131
10.1-5ջ���˺�ɾ��Ԫ��ֻ����ͬһ�˽��У����еĲ��˲�����ɾ�������ֱ������˽��У�
�����ǲ�ͬ�ģ���һ��˫�˶���(deque)��������ɾ�����������������˽��С�д��4��
ʱ���ΪO(1)�Ĺ��̣��ֱ�ʵ����˫�˶��е����˲��˺�ɾ��Ԫ�صĲ������ö�������һ��
����ʵ�ֵġ�

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