/* 합병 정렬의 개념을 이용하여 정렬된 2개의 데이터 리스트를 합치는 함수 merge2() */

int merge2(int a1[], int a2[], int a[], int n1, int n2)
{
	int i = 0, j = 0, k = 0;

	while (i < n1 && j < n2) {
		if (a1[i] <= a2[j])
			a[k++] = a1[i++];
		else
			a[k++] = a2[j++];
	}
	
	printf("i = %d, j = %d, k = %d\n", i, j, k);
	if (i == n1)
		while (j < n2)
			a[k++] = a2[j++];
	else
		while (i < n1)
			a[k++] = a1[i++];
	
	return k;
}
