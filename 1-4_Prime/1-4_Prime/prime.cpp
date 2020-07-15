#include <stdio.h>
#include <math.h>	// sqrt 함수 사용을 위해 필요

// 소수 판별 함수, 2 ~ N-1 까지의 정수로 나누어 보는 방법
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

// 개선된 방안, 2 ~ 루트N 까지의 정수로 나누어 보는 방법
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

	// 소수가 맞으면 1, 아니면 0
	printf("%d\n", is_prime(n));
	printf("%d\n", is_prime2(n));
}
*/