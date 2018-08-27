#include <stdio.h>
int N; // 동전 종류 수.
int K; // 그 가치의 합.
int A[11];
int ans;
int main(void){
	scanf("%d %d",&N,&K);
	for(int i=1;i<=N;i++)
		scanf("%d",&A[i]);
	for(int i=N;i>=1;i--){
		ans = ans + K/A[i];
		K = K % A[i];
	}
	printf("%d",ans);
	return 0;
}
