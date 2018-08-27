#include <stdio.h>
 
int main(void)
{
    int a, b;
     
    scanf("%d %d",&a,&b); // 두 정수 입력 받음
    double ans = ((double)a/(double)b); // 두 정수를 실수로 변환한 다음 나눈 값을 실수형 변수에 저장
    printf("%.9f",ans); // 결과값 출력
 
    return 0;
}