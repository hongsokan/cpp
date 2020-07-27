#include <stdio.h>
#include <string.h>

// Skeletor (기본 골격)
class String
{
protected:
	char *m_pBuffer; // 스트링 버퍼
					 // 내부 함수들
	void _init();
	void _clear();
	void _copy(const char * lpsz);
public:
	// constructors, destructor
	// operators
	// other member functions
};

// 스트링 버퍼 초기화
void String::_init()
{
	m_pBuffer = 0;
}

// m_pBuffer가 null이 아니면, 메모리 해제
void String::_clear()
{
	if (m_pBuffer) // != 0
		delete[] m_pBuffer;
	_init();
}

// 인자로 string을 받으면 복사
void String::_copy(const char * lpsz)
{
	if (lpsz != 0) {
		int len = strlen(lpsz);
		m_pBuffer = new char[len + 1]; // 입력 받은 길이만큼 메모리 할당
		if (m_pBuffer)
			strcpy(m_pBuffer, lpsz);
	}
}


// #include <stdio.h>

// 전역변수, static(정적 변수)
int global;

void main()
{
	// 외부에서 알려지진 않지만, static
	static int staticVar = 10;

	// 동적변수, dynamic
	char* dynamic = new char[10];
	// do something...
	delete[] dynamic;

	// 자동변수, 지역변수, auto, local
	int local1 = 0;
	if (local1 == 0) {
		// 자동변수
		int local2;
		local2 = 0;
	}
	// do something...
}