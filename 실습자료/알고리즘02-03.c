#include <stdio.h>
main()
{
	int i, n, data, large=0;
	printf("������ ������ �Է��Ͻÿ� >> ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("������ �Է��Ͻÿ� >> ");
		scanf("%d", &data);
		if (data > large)
			large = data;
	}
	printf("%d���� �� �� ���� ū ���� %d", n, large);
}