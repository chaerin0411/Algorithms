/* 삽입 정렬 함수 insertion() */
/* i개의 데이터(a[0]~a[i-1])가 이미 정렬되어 있다면 다음 데이터 a[i]를 오름차순을 유지하도록 삽입하는 방법 */
#include <stdio.h>

void insertion(int a[], int n);

main()
{
    int list[] = { 12, 17, 25, 37, 48, 52, 86, 1, 50, 100 };
    int i, n;


    n = sizeof(list) / sizeof(int);
    insertion(list, n);

    printf("정렬된 데이터 리스트 : \n");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);

}

void insertion(int a[], int n)
{

    int i, j, idata;
    for (i = 1; i <= n - 1; i++) {
        idata = a[i];
        j = i - 1;
        while (a[j] > idata && j >= 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = idata;
    }
}