#include <stdio.h>
#include <string.h>

// Skeletor (�⺻ ���)
class String
{
protected:
	char *m_pBuffer; // ��Ʈ�� ����
					 // ���� �Լ���
	void _init();
	void _clear();
	void _copy(const char * lpsz);
public:
	// constructors, destructor
	// operators
	// other member functions
};

// ��Ʈ�� ���� �ʱ�ȭ
void String::_init()
{
	m_pBuffer = 0;
}

// m_pBuffer�� null�� �ƴϸ�, �޸� ����
void String::_clear()
{
	if (m_pBuffer) // != 0
		delete[] m_pBuffer;
	_init();
}

// ���ڷ� string�� ������ ����
void String::_copy(const char * lpsz)
{
	if (lpsz != 0) {
		int len = strlen(lpsz);
		m_pBuffer = new char[len + 1]; // �Է� ���� ���̸�ŭ �޸� �Ҵ�
		if (m_pBuffer)
			strcpy(m_pBuffer, lpsz);
	}
}


// #include <stdio.h>

// ��������, static(���� ����)
int global;

void main()
{
	// �ܺο��� �˷����� ������, static
	static int staticVar = 10;

	// ��������, dynamic
	char* dynamic = new char[10];
	// do something...
	delete[] dynamic;

	// �ڵ�����, ��������, auto, local
	int local1 = 0;
	if (local1 == 0) {
		// �ڵ�����
		int local2;
		local2 = 0;
	}
	// do something...
}