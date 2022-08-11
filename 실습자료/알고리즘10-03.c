/* 연결 리스트를 이용한 큐의 구현 */
/* 다음은 struct course_node 타입의 구조체를 기본 노드로 하는 연결 리스트 자료구조를 기본으로 
주어진 파일 안의 강좌번호(courseid), 담당교수이름(tname), 수강생 수(snum), 강의실 번호(roomnum)를 읽어 
마지막으로 자기노드와 같은 타입의 포인터인 struct course_node *(course_list_pointer)인 next를 이용하여 큐 형식으로 노드를 연결하는 프로그램이다. 
같은 입력파일을 사용하여 같은 처리를 하는 2.1.3절의 수강신청 파일을 배열로 처리하는 예와 비교하면서 연결 리스트 프로그래밍 과정을 이해하도록 하자 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CNUM 50

typedef struct course_node* course_list_pointer;
struct course_node {
	char courseid[10];
	char tname[20];
	unsigned snum;
	unsigned roomnum;
	course_list_pointer next;
};

void printout_over40(course_list_pointer ptr);
void search_prof(course_list_pointer ptr, char name[]);
void search_room(course_list_pointer ptr, unsigned sroomnum);
main(int argc, char* argv[])
{
	FILE* coursedb;
	course_list_pointer temp, before, ptr = NULL;
	char sprof[20];
	unsigned sroomnum;

	if ((coursedb = fopen(argv[1], "r")) == NULL) {
		printf("데이터 파일을 열 수 없습니다 \n");
		exit(1);
	}
	temp = (course_list_pointer)malloc(sizeof(struct course_node));
	while (fscanf(coursedb, "%s %s %u %u", (temp->courseid), (temp->tname), &(temp->snum), &(temp->roomnum)) != EOF) {
		// 큐 방식으로 연결하기
		if (ptr)
			before->next = temp;
		else
			ptr = temp;
		before = temp;
		temp = (course_list_pointer)malloc(sizeof(struct course_node));
	} 
	before->next = NULL;
	printf("수강인원이 40명 이상인 강좌 코드 번호를 출력하시오.\n");
	printout_over40(ptr);

	printf("검색하고자 하는 교수이름 입력 : ");
	scanf("%s", sprof);
	printf("%s 교수가 강의하는 강좌 코드와 강의실 번호를 출력하시오.\n", sprof);
	search_prof(ptr, sprof);

	printf("검색하고자 하는 강의실 번호 입력 : ");
	scanf("%u", &sroomnum);
	printf("%u 강의실에 수업하는 강좌 코드와 담당 교수를 출력하시오.\n", sroomnum);
	search_room(ptr, sroomnum);
}
void printout_over40(course_list_pointer ptr)
{
	for (; ptr; ptr = ptr->next)
		if (ptr->snum >= 40)
			printf("%s\n", ptr->courseid);
}
void search_prof(course_list_pointer ptr, char name[])
{
	for (; ptr; ptr = ptr->next)
		if (!strcmp(ptr->tname, name))
			printf("%s\t%u\n", ptr->courseid, ptr->roomnum);
}
void search_room(course_list_pointer ptr, unsigned sroomnum)
{
	for (; ptr; ptr = ptr->next)
		if (ptr->roomnum == sroomnum)
			printf("%s\t%s\n", ptr->courseid, ptr->tname);
}