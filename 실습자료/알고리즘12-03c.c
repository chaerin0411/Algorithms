/* 다음에서 설명하는 함수 bubble(), print_item(), bsearch_stock()을 작성하고 이를 호출하는 main()을 작성하여 완성하는 과정을 이해하시오 */
/* 각 행에 물품코드와 그 물품의 재고개수를 임의의 순으로 저장하고 있는 파일(bitem.d)로부터 n*2의 2차원의 배열 stock에 데이터를 읽어 들인다.
bubble()정렬에 의하여 물품의 내림차순으로 정리한 후 print_item()으로 stock에 저장하고 있는 물품코드를 출력해준다.
그리고 재고갯수를 확인하고자 하는 물품코드(item_code)를 입력받아 이를 파라메터로 함수 bsearch_stock()를 호출한다.
bsearch_stock함수는 이진검색을 한 후, 그 물품이 있으면 해당 물품의 재고갯수를, 없으면 재고물품이 없다고 출력한다. */

#include <stdio.h>
#include <stdlib.h>
#define INUM 100

int bsearch_stock(unsigned a[][2], int n, unsigned key);
void print_item(char *heading, unsigned a[][2], int n);
void bubble(unsigned a[][2], int n);

main(int argc, char* argv[])
{
	FILE* stockdb;
	unsigned stock[INUM][2], item_code;
	int k = 0, s;

	if ((stockdb = fopen(argv[1], "r")) == NULL) {
		printf("Cannot open read file.. ..\n");
		exit(1);
	}
	while ((fscanf(stockdb, "%u %u", &stock[k][0], &stock[k][1])) != EOF)
		k++;
	print_item("임의로 저장된 물품코드 : \n", stock, k);

	// 물품코드의 내림차순으로 정렬
	bubble(stock, k);
	print_item("내림차순으로 정렬된 물품코드 : \n", stock, k);

	// 검색
	printf("검색할 item number 입력 : ");
	scanf("%u", &item_code);
	s = bsearch_stock(stock, k, item_code);
	if (s == -1)
		printf("재고물품이 없습니다\n");
	else
		printf("%u의 재고개수 = %u\n", stock[s][0], stock[s][1]);
}

void bubble(unsigned a[][2], int n)
{
	int i = n - 1, j, flag = 1;
	unsigned tmp0, tmp1;

	while (flag && i != 0) {
		flag = 0;
		for (j = 0; j <= i - 1; j++) {
			if (a[j][0] < a[j + 1][0]) {
				flag = 1;
				tmp0 = a[j][0];
				a[j][0] = a[j + 1][0];
				a[j + 1][0] = tmp0;
				tmp1 = a[j][1];
				a[j][1] = a[j + 1][1];
				a[j + 1][1] = tmp1;
			}
		}
		i--;
	}
}

void print_item(char* heading, unsigned a[][2], int n)
{
	int i;
	printf(heading);
	for (i = 0; i < n; i++)
		printf("%u\n", a[i][0]);
}

int bsearch_stock(unsigned a[][2], int n, unsigned key)
{
	int left = 0, right = n - 1, mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (key < a[mid][0])
			left = mid + 1;
		else if (key > a[mid][0])
			right = mid - 1;
		else
			return mid;
	}
	return -1; /* not exist */
}