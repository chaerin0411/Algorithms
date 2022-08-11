#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CNUM 50
typedef struct course {
	char courseid[10];
	char tname[20];
	unsigned snum;
	unsigned roomnum;
} cinform;

main(int argc, char* argv[])
{
    int i = 0, dnum;
    char sprof[20];
    unsigned sroomnum;
    cinform cdb[MAX_CNUM];
    FILE* coursedb;

    if ((coursedb = fopen(argv[1], "r")) == NULL) {
        printf("데이터 파일을 열 수 없습니다 \n");
        exit(1);
    }
    while (fscanf(coursedb, "%s %s %u %u", cdb[i].courseid,
        cdb[i].tname, &(cdb[i].snum), &(cdb[i].roomnum)) != EOF)  i++;
    dnum = i;
    printf("수강인원이 40명 이상인 강좌 코드 번호를 출력하시오.\n");
    for (i = 0; i < dnum; i++)
        if (cdb[i].snum >= 40) printf("%s\n", cdb[i].courseid);

    printf("검색하고자 하는 교수이름 입력 : ");
    scanf("%s", sprof);
    printf("%s 교수가 강의하는 강좌코드와 강의실 번호를 출력하시오.\n", sprof);
    for (i = 0; i < dnum; i++)
        if (!strcmp(cdb[i].tname, sprof))
            printf("%s\t%u\n", cdb[i].courseid, cdb[i].roomnum);

    printf("검색하고자 하는 강의실 번호 입력 : ");
    scanf("%u", &sroomnum);
    printf("%u 강의실에서 수업하는 강좌코드와 담당교수를 출력하시오.\n",
        sroomnum);
    for (i = 0; i < dnum; i++)
        if (cdb[i].roomnum == sroomnum)
            printf("%s\t%s\n", cdb[i].courseid, cdb[i].tname);
}
