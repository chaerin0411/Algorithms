#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int gcd(int x, int y);

main(int argc, char* argv[])
{
	int a, b, result, answer;
	int correct = 0, i = 0;
	FILE* infile;
	if (argc != 2) {
		printf("실행인수를 잘못 주었습니다...\n");
		exit(1);
	}

	if ((infile = fopen(argv[1], "r")) == NULL) {
		printf("입력 파일을 열 수 없습니다.\n");
		exit(1);
	}

	while (fscnaf(infile, "%d %d", &a, &b) != EOF) {
		printf("%d : gcd(%d, %d) = ", i + 1, a, b);
		scanf("%d", &answer);
		result = gcd(a, b);
		if (answer != result)
			printf("Answer : gcd(%d, %d) = %d\n", a, b, result);
		else {
			printf("Correct....\n");
			correct++;
		}
		i++;
	}

	printf("%d 문제 중에 %d 문제 통과하셨습니다....\n", i, correct);
}

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}