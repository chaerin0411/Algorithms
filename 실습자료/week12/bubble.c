#include <stdio.h>

void bubble(int a[], int n);

main()
{
    int list[]={12, 17, 25, 33, 48, 52, 86, 37, 100, 70};
    int i, n;
  
    n=sizeof(list)/sizeof(int);
    bubble(list, n);
    printf("���ĵ� ������ ����Ʈ: \n"); 
    for (i=0; i < n; i++)
	printf("%d ", list[i]);
   
}

void bubble(int a[], int n)
{
    int i=n-1, j, tmp;

    while (i != 0)  {
	    for (j=0; j <=i-1; j++) {
	   
	       if (a[j] > a[j+1]) {
		      tmp = a[j];
		      a[j] = a[j+1];
		      a[j+1] = tmp;
		   }
		}
	    i--;
    }
}         


