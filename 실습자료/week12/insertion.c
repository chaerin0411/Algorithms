#include <stdio.h>

void insertion(int a[], int n);

main()
{
    int list[]={12, 17, 25, 37, 48, 52, 86};
    int i, n;

   
    n=sizeof(list)/sizeof(int);
    insertion(list, n);

    printf("정렬된 데이터 리스트: \n"); 
    for (i=0; i < n; i++)
	    printf("%d ", list[i]); 
  
}

void insertion(int a[], int n)
{

    int i, j, key;
    for (i=1; i <= n-1; i++) {
        key = a[i];
        j = i-1;
	    while (a[j] > key && j >= 0) {
	        a[j+1] = a[j];
	        j--;
		}
	    a[j+1] = key;
    }
}