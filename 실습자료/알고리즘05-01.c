#include <stdio.h>
void selection_sort(int a[], int n);
void print_data(int a[], int n);
main()
{
	int list[] = { 40, 30, 80, 70, 100, 10, 90, 20, 170, 60, 80 };
	int n = sizeof(list) / sizeof(int);
	print_data(list, n);
	selection_sort(list, n);
	printf("\n --------------------------------  \n");
	print_data(list, n);
} /* main */

void print_data(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d [%d] \n", i, a[i]);
} /* display */

void selection_sort(int list[], int n)
{
	int s, m, j, temp;

	for (s = 0; s < n - 1; s++) {
		m = s;
		for (j = s + 1; j < n; j++)
			if (list[j] < list[m]) m = j;
		temp = list[s];
		list[s] = list[m];
		list[m] = temp;
	}
}
