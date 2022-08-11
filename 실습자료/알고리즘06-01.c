#include <stdio.h>
int bsearch(int a[], int n, int key);
void selection_sort(int a[], int n);

main()
{
	int list[] = { 82, 120, 30, 40, 5, 90, 77, 25, 45, 100, 10, 79, 31, 55, 87 };
	int n = sizeof(list) / sizeof(int);
	int key, i;
	char sorted;

	printf("Is your data set sorted(y/n)? ");
	scanf("%c", &sorted);

	if (sorted == 'n') selection_sort(list, n);
	printf("Eneter a key: ");
	scanf("%d", &key);

	if ((i = bsearch(list, n, key)) != -1)
		printf("%d exist at [%d]\n", key, i + 1);
	else
		printf("%d does not not exist\n", key);
} /* main */

void selection_sort(int a[], int n)
{
	int s, m, j;
	int temp;

	for (s = 0; s < n - 1; s++) {
		m = s;
		for (j = s + 1; j < n; j++)
			if (a[j] < a[m]) m = j;
		temp = a[s];
		a[s] = a[m];
		a[m] = temp;
	} /* for */
} /* sort */

int bsearch(int a[], int n, int key)
{
	int mid;
	int left = 0, right = n - 1;

	while (left <= right) {
		mid = (left + right) / 2;
		if (key > a[mid]) left = mid + 1;
		else if (key < a[mid]) right = mid - 1;
		else return mid;
	} /* while */
	return -1; /* not exist */
} /* bsearch */