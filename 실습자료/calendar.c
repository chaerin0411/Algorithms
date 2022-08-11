/* ================= calendar.c ==================== */
#include <stdio.h>
int isyoon(int); /* 사용자 정의 함수 */
int main() {
    int year; /* 입력받은 연도 */
    int month; /* 입력받은 달 */
    int i; /* 입력받은 달이 1월부터 며칠 후인지 계산 */
    int j; /* 일 수 */
    int p; /* 각 달 1일의 요일 */
    int sum = 0; /* 입력받은 연도의 달이 1900년부터 며칠 후인지 계산 */
    int chk = 0; /* 윤년 확인 변수 */
    int monthArray[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; /* 기본 1~12월 일수 */
    printf("출력을 원하는 연도와 달을 입력하세요 :");
    scanf("%d %d", &year, &month);
    if (isyoon(year)) /* 사용자 정의 함수로 윤년 판단 */
    {
        chk = 1;
        monthArray[1]++; /* 윤년이면 2월을 29일로 계산 */
    }
    else
        chk = 0;
    sum = 365;
    for (i = 1990; i < year; i++) /* 1990년부터 입력받은 연도의 저번연도까지 며칠인지 계산 */
    {
        if (isyoon(i))
            sum += 366;
        else
            sum += 365;
    }
    for (i = 0; i < month - 1; i++) /* 1월부터 입력받은 달의 저번 달까지 며칠인지 계산 */
    {
        sum += monthArray[i];
    }
    p = sum % 7; /* 입력받은 연도의 1월1일이 무슨 요일인지 계산 */
    p = p + 1;
    printf(" < 해당 달력 출력 >\n"); /* for 반복문을 사용하여 입력받은 연도의 달 출력 */
    printf(" 일 월 화 수 목 금 토\n\n");
    for (j = 1; j < p; j++) /* 각 달의 1일 위치 조정 */
    {
        printf("   ");
    }
    for (i = 1; i <= monthArray[month - 1]; i++)
    {
        printf("%3d", i);
        p = p + 1;
        if (p > 7)
        {
            printf("\n\n");
            p = 1;
        }
    }
    printf("\n\n");
}
int isyoon(int year) /* 사용자 정의 함수 */
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) /* if문을 사용하여 윤년 판단 */
    {
        return 1; /* 윤년이면 1값을 반환 */
    }
    else
    {
        return 0; /* 윤년이 아니면 0값을 반환 */
    }
}
