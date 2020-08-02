#pragma once

// class SimpleList
typedef void* POS;

template <class TYPE> class SimpleList
{
public:
	enum Exception {
		INVALID_POS, EMPTY_LIST
	};
	// constructor/destructors
	// other operations
	protected;
	struct Node {
		TYPE data;
		Node* pNext;
	};
	Node *m_pNodeHead;
	Node *m_pNodeTail;
	int m_nCount;
};

// Initialization
// Head와 Tail 동시에 생성하여, 그 중간에 값 추가 및 삭제
template <class TYPE> void SimpleList<TYPE>::_init()
{
	m_pNodeHead = new Node;
	m_pNodeTail = new Node;

	m_pNodeHead->pNext = m_pNodeTail;
	m_pNodeTail->pNext = m_pNodeTail;

	m_nCount = 0;
}

// InsertNext
// pos가 가리키는 node 뒤에 newElem 추가
template <class TYPE>
POS SimpleList<TYPE>::InsertNext(POS pos, const TYPE& newElem)
{
	Node *pNode = (Node*)pos; // 전체 노드를 가리키는 pNode
	if (pNode == 0) return 0;
	if (pNode == m_pNodeTail) return 0; // tail 뒤에는 데이터 추가 불가

	Node *pNewNode = new Node; // 새로운 node 만들고
	pNewNode->data = newElem; // data 넣고

	pNewNode->pNext = pNode->pNext; // 새로운 node의 pNext = 기존 노드의 pNext
	pNode->pNext = pNewNode; // 그리고 기존 node의 pNext는 새로 추가한 노드
							 // 반대 순서로 하면 에러 (기존 노드 pNext 먼저 수정하면, 다음 node 어딨는지 모르게 됨)

	m_nCount++;

	return pNewNode;
}

// DeleteNext
template <class TYPE>
POS SimpleList<TYPE>::DeleteNext(POS pos)
{
	Node *pNode = (Node*)pos; // 전체 노드를 가리키는 pNode
	if (pNode == 0)
		throw INVALID_POS;
	if (pNode->pNext == m_pNodeTail)
		throw INVALID_POS;

	// 기존에 연결된 2개의 포인터 끊어내고
	Node *pNodeDel = pNode->pNext;
	pNode->pNext = pNode->pNext->pNext;

	TYPE rt = pNodeDel->data;
	delete pNodeDel; // 삭제 할 node 메모리 해제

	m_nCount--;

	return rt;
}

// Destruction
template <class TYPE>
SimpleList<TYPE>::~SimpleList()
{
	RemoveAll();
	if (m_pNodeHead)
		delete m_pNodeHead;
	if (m_pNodeTail)
		delete m_pNodeTail;
	m_pNodeHead = m_pNodeTail = 0;
	m_nCount = 0;
}

template <class TYPE>
void SimpleList<TYPE>::RemoveAll()
{
	int n = GetCount();
	for (int i = 0; i < n; i++)
		RemoveHead();
}

template <class TYPE>
TYPE SimpleList<TYPE>::RemoveHead()
{
	return DeleteNext(m_pNodeHead);
}


template <class TYPE> class SimpleList
{
	//........
	TYPE& GetHead();
	TYPE GetHead() const; // 함수 내부에서 객체 값 변하지 않는다는 명시적 표현

	TYPE& GetNext(POS& pos);
	TYPE GetNext(POS& pos) const;

	TYPE& GetAt(POS pos);
	TYPE GetAt(POS pos) const;
	//........
}


void dump_list_int(const SimpleList<int>& list) // const, 내부에서 값 바뀌지 않음
{
	POS pos = list.GetHeadPosition();
	while (pos) {
		// const버전 GetNext 사용
		printf("%d", list.GetNext(pos)); // TYPE GetNext(POS& pos) const;
	}
	printf("\n");
}

void func(SimpleList<int>& list)
{
	// non-const 버전 GetHead 사용
	list.GetHead() = 5; // TYPE& GetNext(POS& pos); 값이 바뀔 수 있음
}