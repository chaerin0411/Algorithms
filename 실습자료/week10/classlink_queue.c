#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct course_node *course_list_pointer;
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

main(int argc, char *argv[])
{
	FILE *coursedb;
	course_list_pointer temp, before, ptr = NULL;
	char sprof[20];
	unsigned sroomnum;

	if ((coursedb = fopen(argv[1], "r")) == NULL) {
		printf("������ ������ �� �� �����ϴ� \n");
		exit(1);
	}

	temp = (course_list_pointer)malloc(sizeof(struct course_node));
	while (fscanf(coursedb, "%s %s %u %u", temp->courseid,
		temp->tname, &(temp->snum), &(temp->roomnum)) != EOF) {
		if (ptr)
			before->next = temp;
		else
			ptr = temp;
		before = temp;
		temp = (course_list_pointer)malloc(sizeof(struct course_node));
	}
	before->next = NULL;

	printf("����� ���¹�ȣ : \n");
	temp = ptr;
	for (; temp; temp = temp->next)
		printf("%s\n", temp->courseid);

	printf("==============================================\n");
	printf("�����ο��� 40�� �̻��� ���� �ڵ� ��ȣ�� ����Ͻÿ�.\n");
	printout_over40(ptr);

	printf("�˻��ϰ��� �ϴ� �����̸� �Է� : ");
	scanf("%s", sprof);
	printf("%s ������ �����ϴ� �����ڵ�� ���ǽ� ��ȣ�� ����Ͻÿ�.\n",
		sprof);
	search_prof(ptr, sprof);

	printf("�˻��ϰ��� �ϴ� ���ǽ� ��ȣ �Է� : ");
	scanf("%u", &sroomnum);
	printf("%u ���ǽǿ� �����ϴ� �����ڵ�� ��米���� ����Ͻÿ�.\n",
		sroomnum);
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