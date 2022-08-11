/* 단어 이진 검색 트리 구축에 대하여 수업한 내용을 바탕으로 다음 코드를 시작으로 insert_node, search, inorder 함수 정의를 작성하여 완성하시오. */

#include <stdio.h>
#include <string.h>

typedef struct node {
	struct node* left;
	char* word;
	struct node* right;
} NODETYPE;

int insert_node(NODETYPE* root, char* str);
NODETYPE* search(NODETYPE* root, char* key);
void inorder(NODETYPE* root);

main()
{
	NODETYPE* tree = NULL;
	NODETYPE* ptr;
	char wbuf[30];

	printf(" 검색 트리에 저장할 단어를 입력하세요.\n 입력의 끝에는 quit를 입력하세요.\n");

	while (strcmp(gets(wbuf), "quit")) {
		if (!tree) { // 트리가 비었을 때 tree == NULL
			tree = (NODETYPE*)malloc(sizeof(NODETYPE));
			tree->word = (char*)malloc(strlen(wbuf) + 1);
			strcpy(tree->word, wbuf);
			tree->left = tree->right = NULL;
		}
		else
			insert_node(tree, wbuf);
	}
	printf("\n\nEnter a key to search : ");
	gets(wbuf);
	ptr = search(tree, wbuf);
	if (ptr)
		printf("%s is in this tree.\n\n", ptr->word);
	else
		printf("%s not exist.\n\n", wbuf);

	printf("---트리안의 단어들 (사전식 순서---------------------\n\n");
	inorder(tree);
}

NODETYPE* search(NODETYPE* root, char* key)
{
	NODETYPE* tptr = root;
	int cmp;
	while (tptr) {
		cmp = strcmp(key, tptr->word);
		if (cmp < 0)
			tptr = tptr->left;
		else if (cmp > 0)
			tptr = tptr->right;
		else // found
			return tptr;
	}
	return NULL; // not found
}

int insert_node(NODETYPE* root, char* word)
{
	NODETYPE* tptr = root, * before;
	int cmp;
	while (tptr) {
		cmp = strcmp(word, tptr->word);
		if (cmp < 0) {
			before = tptr;
			tptr = tptr->left;
		}
		else if (cmp > 0) {
			before = tptr;
			tptr = tptr->right;
		}
		else // found
			return 0;
	}
	tptr = (NODETYPE *)malloc(sizeof(NODETYPE));
	tptr->word = (char*)malloc(strlen(word) + 1);
	strcpy(tptr->word, word);
	tptr->left = tptr->right = NULL;
	if (cmp < 0) before->left = tptr;
	else before->right = tptr;
	return 1;
}

void inorder(NODETYPE* ptr) {
	if (ptr) {
		inorder(ptr->left);
		printf("%s\n", ptr->word);
		inorder(ptr->right);
	}
}