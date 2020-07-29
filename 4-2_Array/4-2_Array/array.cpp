#include <iostream>
using namespace std;

int array[3][3] =
{
{ 1, 2, 3 },
{ 4, 5, 6 },
{ 7, 8, 9 }
};

// int array[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

// sizeof(array[0]) == 12, sizeof(array[0][0]) == 4

// 2차원
// *m은 시작점 가리키는 포인터, n1 x n2 가 배열의 크기
int average(int *m, int n1, int n2)
{
	int i, j;
	int sum = 0;
	for (i = 0; i < n1; i++)
		for (j = 0; j < n2; j++)
			sum += m[i*n2 + j];
	return sum / (n1 * n2);
}

// 3차원
int tri[3][4][2];
int func(int *m, int n1, int n2, int n3)
{
	// ...
	int sum = 0;

	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			for (int k = 0; k < n3; k++)
				sum += m[i*n2*n3 + j * n3 + k];

	return sum;
}


int main(void)
{
	int array[3][3];
	int averageResult = average(&array[0][0], 3, 3);

	int r = 0;
	r = func(tri, 3, 4, 2);
}