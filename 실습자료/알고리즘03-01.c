#include <stdio.h>
main()
{
	int n, i, x, allzero = 1;
	long mult = 1;

	printf("Enter the number of to be processed : ");
	scanf("%d", &n);
	printf("Enter %d numbers : \n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x != 0) {
			mult *= x;
			allzero = 0;
		}
	}
	if (allzero) mult = 0;
	printf("Answer = %d\n", mult);
}