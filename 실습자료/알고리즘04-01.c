#include <stdio.h>
int gcd(int x, int y);

main()
{
	int gvalue;
	int a, b, again = 1;

	while (again) {
		printf("최대공약수를 구할 두 수를 입력 하세요. ");
		scanf("%d %d", &a, &b);
		gvalue = gcd(a, b);
		printf("gcd(%d, %d) = %d\n\n", a, b, gvalue);
		printf("계속하실래요?(1/0)");
		scanf("%d", &again);
	}
}

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}