#include <cstdio>
#include <vector>
using namespace std;
int N; // 동전 종류 수.
int K; // 그 가치의 합.
vector<int> A;
int ans;
int main(void){
	scanf("%d %d",&N,&K);
	A.resize(N+1);
	for(int i=1;i<=N;i++)
		scanf("%d",&A[i]);
	for(int i=N;i>=1;i--){
		ans = ans + K/A[i];
		K = K % A[i];
	}
	printf("%d",ans);
	return 0;
}
