#include <cstdio>
#include <string.h>

using namespace std;

int n; // 2*n 크기의 직사각형. 1 <= n <= 1000
int memo[1001]; // n의 최대값 1,000 + 1

int solve(int n) 
//함수의 정의 : 2*n 크기의 직사각형을 1*2, 2*1, 2*2 타일로 채우는 방법의 수를 리턴.
{
    // 기저 조건.
    if( n == 1 ) // 2*1
        return 1; // (2*1 1개) -> 1가지 경우.
    if( n == 2 ) // 2*2
        return 3; // ((1*2 2개) or (2*1 2개) or (2*2 1개)) -> 3가지 경우.

    int &ret = memo[n]; // 주소 일치.

    if( ret != -1 ) // n에 대해서 이미 계산을 한 적이 있다면
        return ret; // 저장되어 있던 그 값을 리턴.

    ret = (solve(n-1) + 2*solve(n-2))%10007; // 점화식.

    return ret;
}

int main(void)
{
    scanf("%d",&n);
    memset(memo,-1,sizeof(memo)); // 결과값으로 절대 나올 수 없는 -1로 초기화.
    printf("%d",solve(n)); // 첫째 줄에 solve(n)을 10,007로 나눈 나머지를 출력.
    return 0;
}