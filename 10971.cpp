#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int N, W[101][101], ans = INT_MAX;
vector<int> C; // 도시 방문 순서 순열.
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		C.push_back(i); // 도시 방문 순서 맨 처음 순열 저장.
		for(int j=1;j<=N;j++)
			scanf("%d",&W[i][j]); // 가중치 저장.
	}
	do{
		bool connected = true;
		int sum = 0;
		for(int i=0;i<N-1;i++){ // 도시 방문 순서 순열대로 돌기
			// 두 도시를 오갈 수 없는 경우.
			if(W[C[i]][C[i+1]] == 0) connected = false;
			// 길이 있으면 비용 더하기.
			else sum += W[C[i]][C[i+1]];
		}
		// 해당 순서대로 연결되어 있고, 마지막 도시에서 시작 도시로 갈 수 있다면
		if(connected && W[C[N-1]][C[0]] != 0){
			sum += W[C[N-1]][C[0]];
			if(ans > sum) ans = sum; // 최저값 갱신.
		}
	}while(next_permutation(C.begin(), C.end())); // 순열 돌리기.
	printf("%d",ans);
	return 0;
}
