#include <stdio.h>
#include <math.h>	// sqrt �Լ� ����� ���� �ʿ�

// �Ҽ� �Ǻ� �Լ�, 2 ~ N-1 ������ ������ ������ ���� ���
int is_prime(int n)
{
	int i;
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

// ������ ���, 2 ~ ��ƮN ������ ������ ������ ���� ���
int is_prime2(int n)
{
	int i, sqrn;
	sqrn = (int)sqrt(n);
	for (i = 2; i <= sqrn; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

/*
void main(void)
{
	int n;

	n = 1483;

	// �Ҽ��� ������ 1, �ƴϸ� 0
	printf("%d\n", is_prime(n));
	printf("%d\n", is_prime2(n));
}
*/