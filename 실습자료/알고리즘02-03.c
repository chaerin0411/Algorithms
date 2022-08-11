#include <stdio.h>
main()
{
	int i, n, data, large=0;
	printf("정수의 개수를 입력하시오 >> ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("정수를 입력하시오 >> ");
		scanf("%d", &data);
		if (data > large)
			large = data;
	}
	printf("%d개의 값 중 가장 큰 값은 %d", n, large);
}