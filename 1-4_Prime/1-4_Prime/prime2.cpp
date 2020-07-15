#include <stdio.h>
#include <stdlib.h>	// atoi 사용을 위해
#include <string.h>	// memset 사용을 위해

// 에라토스테네스의 체
// 주어진 정수 N보다 작은 모든 소수를 구한다

int main(int argc, char* argv[])
{
	// 인자가 있어야 함
	if (argc < 2) {
		printf("Usage : prime2 [integer]\n");
		return 0;
	}

	// 주어진 인자는 2보다 큰 수여야 한다
	int n = atoi(argv[1]);
	if (n < 2) {
		printf("Error : n must be greater than 1\n");
		return 0;
	}

	int *parray;

	// 메모리의 할당
	parray = new int[n + 1];	// cpp array는 0부터 시작
	if (parray == 0) {
		printf("Error : memory allocation failed\n");
		return 0;
	}

	// 메모리를 0으로 초기화
	memset(parray, 0, sizeof(int)*(n + 1));

	int i, j;
	// 소수 구하기 루프
	for (i = 2; i <= n; i++) {
		if (parray[i] == 1)	// 이미 지워진 수, 소수가 아니면 다음수로
			continue;
		j = i;	// i를 기점으로 해서
		while ((j += i) <= n) {
			parray[j] = 1;	// i의 배수들을 소수가 아니라고 마킹함
		}
	}

	// 소수의 출력
	for (i = 2; i <= n; i++) {
		if (parray[i] == 0)
			printf("%d ", i);
	}
	printf("\n");

	// 할당된 메모리를 해제
	delete[] parray;
	return 0;
}