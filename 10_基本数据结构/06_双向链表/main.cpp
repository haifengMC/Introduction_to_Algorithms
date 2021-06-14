/*
P134
10.2-1单链表上的动态集合操作 INSERT能否在O1)时间内实现?DELETE操作呢?
10.2-2用一个单链表L实现一个栈。要求操作PUSH和POP的运行时间仍为O(1)。
10.2-3用一个单链表L实现一个队列。要求操作EVQUEUE和DEQUEUE的运行时间仍为O(1)。
10.2-4如前所述，LIST-SEARCH'过程中的每一次循环迭代都需要两个测试:一是检查x≠L.nil，
	另一个是检查工x.key≠k。试说明如何在每次迭代中省略对x≠L.nil的检查。
10.2-5使用单向循环链表实现字典操作INSERT、DELETE和SEARCH，并给出所写过程的运行时间。
10.2-6动态集合操作UNION以两个不相交的集合S1和S2作为输人，并返回集合S=S1 U S2,
	包含S1和S2的所有元素。该操作通常会破坏集合S1和S2。试说明如何选用一种合适的
	表类数据结构,来支持O(1)时间的UNION操作。
10.2-7给出一个theta(n)时间的非递归过程，实现对一个含n个元素的单链表的逆转。要求除存
	储链表本身所需的空间外，该过程只能使用固定大小的存储空间。
10.2-8说明如何在每个元素仅使用一个指针x.np(而不是通常的两个指针nezt和prev)的情况下
	实现双向链表。假设所有指针的值都可视为k位的整型数，且定义x.np = x.next XOR x.prev，
	即x.next和x.prev的k位异或。(NIL的值用О表示。)注意要说明获取表头所需的信息，并说明如何
	在该表上实现SEARCH、INSERT和 DELETE操作，以及如何在O(1)时间内实现该表的逆转。
*/

#include <iostream>
#include <typeinfo>
#include <list>
#include <string>
#include "hList.h"

using namespace std;

int main()
{
	size_t* p = hStdAlloc<size_t>::alloc();
	hStdAlloc<size_t>::create(p, 10);
	cout << p << ":" << *p << endl;
	hStdAlloc<size_t>::destroy(p);
	hStdAlloc<size_t>::dealloc(p);
	list.emplace_back()
	return 0;
}