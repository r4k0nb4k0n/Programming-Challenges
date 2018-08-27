#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int N; // 남은 붕어빵 개수.
int memo[1001];
vector<int> P; // N개일 때의 가격 P(N) 저장하는 리스트.
 
int solve(int N) // 해빈이가 얻을 수 있는 최대 수익, 즉 최대 합.
{
    // 기저 조건.
    if( N == 0 ) // 붕어빵 매진일 때.
        return 0; // 붕어빵 자체가 없으므로 가격도 없다.
    if( N == 1 ) // 붕어빵이 1개만 남았을 때.
        return P[1]; // 붕어빵 1개 가격 리턴.
 
    int &ret = memo[N];
 
    if( ret != -1 ) // 이미 N에 대해 연산한 적이 있다면 
        return ret; //그거에 대한 결과값 리턴.
 
    ret = solve(N-1) + P[1];
     
    for(int i=2;i<=N;i++)
        ret = max(ret,solve(N-i) + P[i]);
 
    return ret;
}
 
int main(void)
{
    scanf("%d",&N);
    P.resize(N+1);
    for(int i=1;i<=N;i++)
        scanf("%d",&P[i]);
    memset(memo,-1,sizeof(memo));
    printf("%d",solve(N));
    return 0;
}