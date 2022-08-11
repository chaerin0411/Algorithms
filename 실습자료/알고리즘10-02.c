/* 연결 리스트를 이용한 스택의 구현 */
/* 다음은 struct list_node 타입의 구조체를 기본 노드로 하는 연결 리스트 자료구조를 기본으로 주어진 파일 안의 아이디(id)와 점수(score)를 읽어 
 마지막으로 자기 노드와 같은 타입의 포인터인 struct list_node *(list_pointer)인 link를 이용하여 스택형식으로 노드를 연결하는 프로그램이다. */

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
		printf("입력 파일을 열 수 없습니다. \n");
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
//	printf("최대 성적을 가진 학생 아이디 : %ld : 성적 : %d\n", high_score->id, high_score->score);
}
void print_list(list_pointer ptr)
{
	for (; ptr; ptr = ptr->link)
		printf("%ld == %d\n", ptr->id, ptr->score);
}
