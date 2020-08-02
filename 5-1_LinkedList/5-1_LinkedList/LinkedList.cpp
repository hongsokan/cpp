#include <stdio.h>
#include "Node.h"
#include "Exception.h"
#include "SimpleList.h"

// instance ���
Node<int> IntNode;
IntNode.SetData(5);

// String type Node ���
typedef Node<String> StringNodeClass;
StringNodeClass StringNode;
StringNode.SetData("aaa");

// ���� ��ü�� instantiation
template Node<double>;


// �ܼ� ���Ḯ��Ʈ ��� ���
SimpleList<int> list;

// ����ó��
try {
	list.GetHead(); // ����ִ� ���, Exception �߻�
}
catch (SimpleList<int>::Exception e) {
	if (e == SimpleList<int>::INVALID_POS)
		printf("catched, Invalid Pointer %d\n", e);
	else if (e == SimpleList<int>::EMPTY_LIST)
		printf("catched, Empty List %d\n", e);

	// GetHead() ���� �޼��� �����ϴ� ���, if () ...; else throw EMPTYLIST;
	// �̷� ������ ��� �ִ� ���Ḯ��Ʈ���� ����ó�� ����

	// try - catch ���� ��� �ִ� ���Ḯ��Ʈ���� list.GetHead(); �ϸ� Debug Error �߻�
}

// SimpleList<int> list;

list.AddHead(1); // AddHead()�� InsertNext()ȣ��
list.AddHead(2); // head - 2 - 1 - ... - tail
				 //..........

POS pos = list.GetHeadPosition(); // ��� �ִ� ��� ���� 0
while (pos)
{
	int n = list.GetNext(pos); // GetNext�� (POS* pos) ����
							   // do something with n
}



#include "DoubleList.h"

// ���� ���Ḯ��Ʈ ����

// Iteration
void func(const DoubleList<String>&list)
{
	POS pos;

	// ������ ��ȸ
	pos = list.GetHeadPosition();
	while (pos) {
		String str = list.GetNext(pos);
		// do something with str
	}

	// ������
	pos = list.GetTailPosition();
	while (pos) {
		String str = list.GetPrev(pos);
		// do something with str
	}
}

#include "Person.h"

DoubleList<Person> list;
list.Add(Person("Jake", 33));
list.Add(Person("Slash", 27));

POS pos = list, Find(Person("Jake", 33));