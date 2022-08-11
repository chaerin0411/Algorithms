#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    struct node *left;
    int eid;
    int syear;
    char grade;
    struct node *right;
} ENODE;

int insert_node(ENODE *root, int num, int year, char score);
ENODE *search(ENODE *root, int key);
void inorder(ENODE *root);
void year_search(ENODE *root, int year);


main()
{
    ENODE *tree=NULL, *ptr;
    int id, year;
    char score;

    printf("  검색 트리에 저장할 사원정보를 입력하세요.\n");
    printf("  사원번호 입사년도 인사등급을 입력하고 \n");
    printf("  입력의 끝에는 (0 0 0)를 입력하세요.\n");

    while (1) {
	   scanf("%d %d %c", &id, &year, &score);
       if (id == 0) break;
	   if (!tree) {  // 트리가 비었을때
	      tree = (ENODE *)malloc(sizeof(ENODE));
	      tree -> eid = id;
          tree -> syear = year;
	      tree -> grade = score;
	      tree->left = tree->right = NULL;
        }
        else
	       insert_node(tree, id, year, score);
    }

    printf("\n 트리에 구축된 사원정보 : \n");

    inorder(tree);

    printf("\n 입사년도 : ");
    scanf("%d", &year);
    year_search(tree, year); 

    getch();
    printf("\n 사원 번호 : ");
    scanf("%d", &id);
    ptr = search(tree, id);
    if (ptr)
	  printf("%d번 사원의 정보 : %d\t%c\n", ptr->eid, ptr->syear, ptr->grade);
    else
	  printf("%d번 사원에 대한 정보는 없습니다.\n", id);


}

ENODE *search(ENODE *root, int key)  {
    ENODE *tptr = root;
    
    while (tptr) {
	if (key < tptr->eid)
	    tptr = tptr -> left;
	else if (key > tptr->eid)
	    tptr = tptr -> right;
	else        // found
	    return tptr;
    }
    return NULL;   // not found
}

int insert_node(ENODE *root, int id, int year, char score)  {
    ENODE *tptr = root, *before=NULL;
    
    while (tptr)  { 
        
	   if (id < tptr->eid)  {
          before = tptr;
	      tptr = tptr -> left;
       }
	   else if (id > tptr->eid) {
          before = tptr;
	      tptr = tptr -> right;
       }
	   else        // found
	      return 0;
    }

    tptr = (ENODE *)malloc(sizeof(ENODE));
    tptr -> eid = id;
    tptr -> syear = year;
    tptr -> grade = score;
    tptr->left = tptr->right = NULL;
    if (id < before->eid) before -> left = tptr;
    else  before -> right = tptr;
    return 1;
}

void inorder(ENODE *ptr) {
    if (ptr) {
	  inorder(ptr->left);
	  printf("%d\t%d\t%c\n", ptr->eid, ptr->syear, ptr->grade);
	  inorder(ptr->right);
    }
}

void year_search(ENODE *ptr, int year) {
    if (ptr) {
	  year_search(ptr->left, year);
	  if ((ptr->syear) == year)
	    printf("%d\t%c\n", ptr->eid, ptr->grade);
	  year_search(ptr->right, year);
    }
}