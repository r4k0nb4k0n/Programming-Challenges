#include <cstdio>
#include <algorithm>
#include <string.h>
  
using namespace std;
  
int memo[1000001]; // N이 최대 10^6이므로 배열 개수를 10^6+1로.
  
int solve(int X) // 정의 : X를 1로 만들기 위해 연산을 사용하는 횟수의 최소값 리턴.
{
    // 기저조건 설정.
    if( X == 2 || X == 3 )
        return 1; // 2나 3을 각각 2나 3으로 나누므로 연산 한번 해주는 것.
      
    int &ret = memo[X]; // 주소 일치.
      
    if( ret != -1 ) // solve(X)가 이미 실행되었다면
        return ret; // 그 값을 리턴.
      
    ret = solve(X-1) + 1; // (3. 1을 뺀다.) + 연산 1번.
      
    if( X % 3 == 0 ) // (1. X가 3으로 나누어 떨어지면,)
        ret = min(ret,solve(X/3)+1); // (1. 3으로 나눈다.)
    if( X % 2 == 0 ) // (2. X가 2로 나누어 떨어지면,)
        ret = min(ret,solve(X/2)+1); // (2. 2로 나눈다.)
      
    return ret;
}
  
int main(void)
{
    int N; // 1 <= N <= 10^6
    scanf("%d",&N);
    memset(memo,-1,sizeof(memo)); // 결과값으로 절대 나올 수 없는 -1로 초기화.
    printf("%d",solve(N));
    return 0;
}