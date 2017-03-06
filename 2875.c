#include <stdio.h>
int main(){
	int N, M, K, T=0;
	scanf("%d %d %d",&N,&M,&K);
	while(N>=2 && M>=1){
		N-=2; // 여자 2
		M-=1; // 남자 1
		T+=1; // 팀 1
	}
	K-=(N+M); // 남은 사람들 수 더해주기
	while(K>0){
		T-=1; // 팀 1씩 빼기
		K-=3; // 사람 3씩 빼기
	}
	printf("%d",T); // 팀 수 출력
	return 0;
}
