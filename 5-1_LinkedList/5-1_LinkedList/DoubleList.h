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


// �ٸ� ��� �տ� ��� �߰�
template <class TYPE>
POS DoubleList<TYPE>::InsertBefore(POS pos, const TYPE& newElem)
{
	if (pos == (POS)m_pNodeHead || pos == 0)
		return 0;

	Node *pNode = (Node*)pos;
	Node *pNewNode = new Node; // �߰��� ���

	pNewNode->data = newElem; // pNewNode�� data �κ� = newElem
	pNode->pPrev->pNext = pNewNode; // pNode->pPrev�� ���� ���, pNext�� pNewNode��
	pNewNode->pPrev = pNode->pPrev; // pNewNode�� pPrev�� pNode�� pPrev��
	pNode->pPrev = pNewNode;
	pNewNode->pNext = pNode;

	m_nCount++;

	return pNewNode;
}


// pNode �ڿ� newNode �߰�
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


// DeleteAt (SimpleList�� DeleteNext, �� �����͸� �𸣱� ������, double�� �� �� �ִ�)
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

