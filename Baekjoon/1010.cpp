#include <cstdio>
#include <cstring>
using namespace std;

int memo[31][31];

int Combination(int N, int M){
	int &ret = memo[N][M];
	if(ret!=-1)
		return ret;
	if(N == M || M == 0)
		ret = 1;
	else
		ret = Combination(N-1, M-1) + Combination(N-1, M);
	return ret;
}

int main(){
	int T, N, M;
	scanf("%d",&T);
	memset(memo,-1,sizeof(memo));
	while(T--){
		scanf("%d %d",&N,&M);
		printf("%d\n",Combination(M,N));
	}
	return 0;
}
