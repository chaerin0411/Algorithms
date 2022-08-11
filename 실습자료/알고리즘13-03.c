/* 
사원번호(eid, long int), 이름(name, 19자 이하의 문자열), 영어성적(escore, int), 소속부서(dcode, 4자의 문자열)로 구성되어 있는 파일이 준비되어 있다.
(1) 파일로부터 데이터를 읽어 사원번호를 기준으로 오름차순으로 정렬하여 출력 파일에 저장한다.
(2) dcode를 읽어 그 부서에 해당하는 사원정보를 출력한다.
(3) 영어 성적이 큰 값부터 사원정보를 출력한다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct employee {
	long eid;
	char name[20];
	int escore;
	char dname[5];

} edatatype;
void quick_sorta(edatatype a[], int left, int right);
void quick_sortd(edatatype a[], int left, int right);

void quick_sorta(edatatype a[], int left, int right)
{
	long pivot;
	int i, j;
	edatatype tmp;

	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left].eid;
		while (i < j) {
			do
				i++;
			while ((a[i].eid < pivot) && (i < right));
			do
				j--;
			while ((a[j].eid > pivot) && (j > left));
			if (i < j) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		if (j != left) {
			tmp = a[j];
			a[j] = a[left];
			a[left] = tmp;
		}
		quick_sorta(a, left, j - 1);
		quick_sorta(a, j + 1, right);
	}
}

void quick_sortd(edatatype a[], int left, int right)
{
	int pivot;
	int i, j;
	edatatype tmp;

	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left].escore;
		while (i < j) {
			do
				i++;
			while ((a[i].escore > pivot) && (i < right));
			do
				j--;
			while ((a[j].escore < pivot) && (j > left));
			if (i < j) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		if (j != left) {
			tmp = a[j];
			a[j] = a[left];
			a[left] = tmp;
		}
		quick_sortd(a, left, j - 1);
		quick_sortd(a, j + 1, right);
	}
}

main(int argc, char* argv[])
{
	edatatype edb[50];
	FILE* infile, * out;
	int i = 0, j;
	char choice;
	char dcode[5];

	if (argc != 3) {
		printf("실행 인자를 잘못 주었습니다. \n");
		exit(1);
	}

	if ((infile = fopen(argv[1], "r")) == NULL) {
		printf("입력 파일을 열 수 없습니다. \n");
		exit(1);
	}

	if ((out = fopen(argv[2], "w")) == NULL) {
		printf("결과 파일을 열 수 없습니다. \n");
		exit(1);
	}

	while (fscanf(infile, "%ld %s %d %s", &(edb[i].eid), edb[i].name, &(edb[i].escore), edb[i].dname) != EOF)
		i++;

	for (j = 0; j < i; j++)
		printf("%ld\t%s\t%d\t%s\n", (edb[j].eid), edb[j].name, (edb[j].escore), edb[j].dname);


	// 1. id의 오름차순으로 파일 저장
	quick_sorta(edb, 0, i - 1);

	printf("\n\nSorted Data .... \n");

	for (j = 0; j < i; j++)
		fprintf(out, "%ld\t%s\t%d\t%s\n", (edb[j].eid), edb[j].name, (edb[j].escore), edb[j].dname);


	// 2. dcode를 읽어 그 부서에 해당하는 사원정보 출력하기

	printf("Sales Department      : S110\n");
	printf("Research Department   : R250\n");
	printf("Managemnet Department : M210\n");
	printf("\nEnter the Department code : ");
	scanf("%s", dcode);

	for (j = 0; j < i; j++)
		if (strcmp(dcode, edb[j].dname) == 0)
			printf("%ld\t%s\t%d\n", (edb[j].eid), edb[j].name, (edb[j].escore));


	// 3. 영어 성적이 큰 값부터 정보 출력하기
	printf("\n\nFrom the hightest English score To the lowest....\n");
	quick_sortd(edb, 0, i - 1);
	for (j = 0; j < i; j++)
		printf("%ld\t%s\t%d\t%s\n", (edb[j].eid), edb[j].name, (edb[j].escore), edb[j].dname);


}
