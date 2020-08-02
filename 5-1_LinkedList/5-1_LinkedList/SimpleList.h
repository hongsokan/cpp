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
// Head�� Tail ���ÿ� �����Ͽ�, �� �߰��� �� �߰� �� ����
template <class TYPE> void SimpleList<TYPE>::_init()
{
	m_pNodeHead = new Node;
	m_pNodeTail = new Node;

	m_pNodeHead->pNext = m_pNodeTail;
	m_pNodeTail->pNext = m_pNodeTail;

	m_nCount = 0;
}

// InsertNext
// pos�� ����Ű�� node �ڿ� newElem �߰�
template <class TYPE>
POS SimpleList<TYPE>::InsertNext(POS pos, const TYPE& newElem)
{
	Node *pNode = (Node*)pos; // ��ü ��带 ����Ű�� pNode
	if (pNode == 0) return 0;
	if (pNode == m_pNodeTail) return 0; // tail �ڿ��� ������ �߰� �Ұ�

	Node *pNewNode = new Node; // ���ο� node �����
	pNewNode->data = newElem; // data �ְ�

	pNewNode->pNext = pNode->pNext; // ���ο� node�� pNext = ���� ����� pNext
	pNode->pNext = pNewNode; // �׸��� ���� node�� pNext�� ���� �߰��� ���
							 // �ݴ� ������ �ϸ� ���� (���� ��� pNext ���� �����ϸ�, ���� node ������� �𸣰� ��)

	m_nCount++;

	return pNewNode;
}

// DeleteNext
template <class TYPE>
POS SimpleList<TYPE>::DeleteNext(POS pos)
{
	Node *pNode = (Node*)pos; // ��ü ��带 ����Ű�� pNode
	if (pNode == 0)
		throw INVALID_POS;
	if (pNode->pNext == m_pNodeTail)
		throw INVALID_POS;

	// ������ ����� 2���� ������ �����
	Node *pNodeDel = pNode->pNext;
	pNode->pNext = pNode->pNext->pNext;

	TYPE rt = pNodeDel->data;
	delete pNodeDel; // ���� �� node �޸� ����

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
	TYPE GetHead() const; // �Լ� ���ο��� ��ü �� ������ �ʴ´ٴ� ����� ǥ��

	TYPE& GetNext(POS& pos);
	TYPE GetNext(POS& pos) const;

	TYPE& GetAt(POS pos);
	TYPE GetAt(POS pos) const;
	//........
}


void dump_list_int(const SimpleList<int>& list) // const, ���ο��� �� �ٲ��� ����
{
	POS pos = list.GetHeadPosition();
	while (pos) {
		// const���� GetNext ���
		printf("%d", list.GetNext(pos)); // TYPE GetNext(POS& pos) const;
	}
	printf("\n");
}

void func(SimpleList<int>& list)
{
	// non-const ���� GetHead ���
	list.GetHead() = 5; // TYPE& GetNext(POS& pos); ���� �ٲ� �� ����
}