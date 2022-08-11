/* 개선된 버블 정렬 함수 bubble_flag() */

#include <stdio.h>

void bubble(int a[], int n);

main()
{
	int list[] = { 12, 17, 25, 33, 48, 52, 86, 37, 100, 70 };
	int i, n;

	n = sizeof(list) / sizeof(int);
	bubble(list, n);
	printf("정렬된 데이터 리스트 : \n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);

}

void bubble(int a[], int n)
{
	int i = n - 1, j, tmp, flag = 1;

	while (flag && i != 0) {
		flag = 0;
		for (j = 0; j <= i - 1; j++) {

			if (a[j] > a[j + 1]) { // 내림차순인 경우, if (a[j] < a[j + 1]) {
				flag = 1;
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
		i--;
	}
	printf("i = %d :: flag = %d\n", i, flag);
}