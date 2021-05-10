/*
P131
10.1-3����ͼ10-2����ͼ��ʾ����ִ�в���ENQUEUE(Q��4)��ENQUEUE(Q��1)��
ENQUEUE(Q��3)��DEQUEUE(Q)��ENQUEUE(Q��8)�� DEQUEUE(Q)ÿһ���Ľ��,
���г�ʼΪ�գ��洢������Q[1..6]�С�
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

