#include <stdio.h>
main()
{
	int n1, n2, n3, large;
	printf("세 수를 입력하시오 >> ");
	scanf("%d, %d, %d", &n1, &n2, &n3);
	if (n1 > n2)
		large = n1;
	else
		large = n2;
	if (n3 > large)
		large = n3;
	printf("large = %d", large);
}