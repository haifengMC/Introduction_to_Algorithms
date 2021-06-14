/*
P134
10.2-1�������ϵĶ�̬���ϲ��� INSERT�ܷ���O1)ʱ����ʵ��?DELETE������?
10.2-2��һ��������Lʵ��һ��ջ��Ҫ�����PUSH��POP������ʱ����ΪO(1)��
10.2-3��һ��������Lʵ��һ�����С�Ҫ�����EVQUEUE��DEQUEUE������ʱ����ΪO(1)��
10.2-4��ǰ������LIST-SEARCH'�����е�ÿһ��ѭ����������Ҫ��������:һ�Ǽ��x��L.nil��
	��һ���Ǽ�鹤x.key��k����˵�������ÿ�ε�����ʡ�Զ�x��L.nil�ļ�顣
10.2-5ʹ�õ���ѭ������ʵ���ֵ����INSERT��DELETE��SEARCH����������д���̵�����ʱ�䡣
10.2-6��̬���ϲ���UNION���������ཻ�ļ���S1��S2��Ϊ���ˣ������ؼ���S=S1 U S2,
	����S1��S2������Ԫ�ء��ò���ͨ�����ƻ�����S1��S2����˵�����ѡ��һ�ֺ��ʵ�
	�������ݽṹ,��֧��O(1)ʱ���UNION������
10.2-7����һ��theta(n)ʱ��ķǵݹ���̣�ʵ�ֶ�һ����n��Ԫ�صĵ��������ת��Ҫ�����
	������������Ŀռ��⣬�ù���ֻ��ʹ�ù̶���С�Ĵ洢�ռ䡣
10.2-8˵�������ÿ��Ԫ�ؽ�ʹ��һ��ָ��x.np(������ͨ��������ָ��nezt��prev)�������
	ʵ��˫��������������ָ���ֵ������Ϊkλ�����������Ҷ���x.np = x.next XOR x.prev��
	��x.next��x.prev��kλ���(NIL��ֵ�ç���ʾ��)ע��Ҫ˵����ȡ��ͷ�������Ϣ����˵�����
	�ڸñ���ʵ��SEARCH��INSERT�� DELETE�������Լ������O(1)ʱ����ʵ�ָñ����ת��
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