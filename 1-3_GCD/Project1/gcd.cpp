#include <stdio.h>

int get_gcd(int u, int v)
{
	int t; // u, v 교환하기 위한 임시변수
	while (u) // u가 0보다 클 동안
	{
		if (u < v) // u가 v보다 크면
		{
			t = u; u = v; v = t; // u, v 교환
		}
		u = u - v;
	}
	return v;
}

// 개선 방안 (나눗셈과 나머지)
int gcd_modulus(int u, int v)
{
	int t; // u, v 교환하기 위한 임시변수
	while (v) // v가 0보다 클 동안
	{
		t = u % v;
		u = v;
		v = t;
	}
	return u;
}

// 재귀
int gcd_recursion(int u, int v)
{
	if (v == 0)
		return u;
	else
		return gcd_recursion(v, u%v);
}

void main(void)
{
	int u, v;
	int gcd;

	u = 280;
	v = 30;

	printf("get_gcd result: ");
	gcd = get_gcd(u, v);
	printf("%d\n", gcd);

	printf("gcd_modulus result: ");
	gcd = gcd_modulus(u, v);
	printf("%d\n", gcd);

	printf("gcd_recursion result: ");
	gcd = gcd_recursion(u, v);
	printf("%d\n", gcd);
}

