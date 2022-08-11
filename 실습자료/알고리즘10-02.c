/* ���� ����Ʈ�� �̿��� ������ ���� */
/* ������ struct list_node Ÿ���� ����ü�� �⺻ ���� �ϴ� ���� ����Ʈ �ڷᱸ���� �⺻���� �־��� ���� ���� ���̵�(id)�� ����(score)�� �о� 
 ���������� �ڱ� ���� ���� Ÿ���� �������� struct list_node *(list_pointer)�� link�� �̿��Ͽ� ������������ ��带 �����ϴ� ���α׷��̴�. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CNUM 50

typedef struct list_node* list_pointer;
struct list_node {
	long id;
	int score;
	list_pointer link;
};
void print_list(list_pointer ptr);
main(int argc, char* argv[])
{
	int i, data;
	list_pointer ptr = NULL, temp, high_score;
	FILE* input;

	if ((input = fopen(argv[1], "r")) == NULL) {
		printf("�Է� ������ �� �� �����ϴ�. \n");
		exit(1);
	}
	temp = (list_pointer)malloc(sizeof(struct list_node));

	while (fscanf(input, "%ld %d", &(temp->id), &(temp->score)) != EOF) {
		if (ptr)
			temp->link = ptr;
		else
			temp->link = NULL;
		ptr = temp;
		temp = (list_pointer)malloc(sizeof(struct list_node));
	}
	print_list(ptr);
//	high_score = find_max(ptr);
//	printf("�ִ� ������ ���� �л� ���̵� : %ld : ���� : %d\n", high_score->id, high_score->score);
}
void print_list(list_pointer ptr)
{
	for (; ptr; ptr = ptr->link)
		printf("%ld == %d\n", ptr->id, ptr->score);
}
