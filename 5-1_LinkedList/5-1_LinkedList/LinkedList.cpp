#include <stdio.h>
#include "Node.h"
#include "Exception.h"
#include "SimpleList.h"

// instance 방법
Node<int> IntNode;
IntNode.SetData(5);

// String type Node 방법
typedef Node<String> StringNodeClass;
StringNodeClass StringNode;
StringNode.SetData("aaa");

// 정의 전체를 instantiation
template Node<double>;


// 단순 연결리스트 사용 방법
SimpleList<int> list;

// 예외처리
try {
	list.GetHead(); // 비어있는 노드, Exception 발생
}
catch (SimpleList<int>::Exception e) {
	if (e == SimpleList<int>::INVALID_POS)
		printf("catched, Invalid Pointer %d\n", e);
	else if (e == SimpleList<int>::EMPTY_LIST)
		printf("catched, Empty List %d\n", e);

	// GetHead() 같은 메서드 구현하는 경우, if () ...; else throw EMPTYLIST;
	// 이런 식으로 비어 있는 연결리스트에서 예외처리 가능

	// try - catch 없이 비어 있는 연결리스트에서 list.GetHead(); 하면 Debug Error 발생
}

// SimpleList<int> list;

list.AddHead(1); // AddHead()는 InsertNext()호출
list.AddHead(2); // head - 2 - 1 - ... - tail
				 //..........

POS pos = list.GetHeadPosition(); // 비어 있는 경우 값은 0
while (pos)
{
	int n = list.GetNext(pos); // GetNext는 (POS* pos) 받음
							   // do something with n
}



#include "DoubleList.h"

// 이중 연결리스트 사용법

// Iteration
void func(const DoubleList<String>&list)
{
	POS pos;

	// 순방향 조회
	pos = list.GetHeadPosition();
	while (pos) {
		String str = list.GetNext(pos);
		// do something with str
	}

	// 역방향
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