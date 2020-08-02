#pragma once

// Skeleton
typedef void* POS;

template <class TYPE> class DoubleList
{
public:
	enum Exception {
		INVALID_POS, EMPTY_LIST
	};
	// constructor/destructors
	// other operations
protected:
	struct Node {
		TYPE data;
		Node* pNext;
		Node* pPrev;
	};
	Node *m_pNodeHead;
	Node *m_pNodeTail;
	int m_nCount;
};


// Initialization
template <class TYPE>
void DoubleList<TYPE>::_init()
{
	m_pNodeHead = new Node;
	m_pNodeTail = new Node;

	m_pNodeHead->pNext = m_pNodeTail;
	m_pNodeHead->pPrev = m_pNodeHead;
	m_pNodeTail->pNext = m_pNodeTail;
	m_pNodeTail->pPrev = m_pNodeHead;

	m_nCount = 0;
}


// 다른 노드 앞에 노드 추가
template <class TYPE>
POS DoubleList<TYPE>::InsertBefore(POS pos, const TYPE& newElem)
{
	if (pos == (POS)m_pNodeHead || pos == 0)
		return 0;

	Node *pNode = (Node*)pos;
	Node *pNewNode = new Node; // 추가할 노드

	pNewNode->data = newElem; // pNewNode의 data 부분 = newElem
	pNode->pPrev->pNext = pNewNode; // pNode->pPrev는 이전 노드, pNext를 pNewNode로
	pNewNode->pPrev = pNode->pPrev; // pNewNode의 pPrev는 pNode의 pPrev로
	pNode->pPrev = pNewNode;
	pNewNode->pNext = pNode;

	m_nCount++;

	return pNewNode;
}


// pNode 뒤에 newNode 추가
template <class TYPE>
POS DoubleList<TYPE>::InsertNext(POS pos, const TYPE& newElem)
{
	if (pos == (POS)m_pNodeTail || pos == 0)
		return 0;

	Node *pNode = (Node*)pos;
	Node *pNewNode = newNode;
	pNewNode->data = newElem;

	pNode->pNext->pPrev = pNewNode;
	pNewNode->pNext = pNode->pNext;
	pNode->pNext = pNewNode;
	pNewNode->pPrev = pNode;

	m_nCount++;
	return pNewNode;
}


// DeleteAt (SimpleList는 DeleteNext, 앞 데이터를 모르기 때문에, double은 알 수 있다)
template <class TYPE>
TYPE DoubleList<TYPE>::DeleteAt(POS pos)
{
	if (!IsValid(pos))
		throw INVALID_POS;

	Node *pNode = (Node*)pos;
	pNode->pPrev->pNext = pNode->pNext;
	pNode->pNext->pPrev = pNode->pPrev;

	TYPE data = pNode->data;
	delete pNode;

	m_nCount--;
	return data;
}

