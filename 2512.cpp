#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;
int MAX=0;
vector<int> v;

bool judge(int x){
	int sum = 0;
	for(int i=0;i<N;i++)
		sum+=(v[i]>x)?x:v[i];
	return sum <= M;
}

int solve(){
	int low=0, high=MAX;
	int mid;

	while(low<=high){
		mid = (low+high)/2;
		if(judge(mid)) low = mid + 1;
		else high = mid-1;
	}

	return low-1;
}

int main(){
	scanf("%d",&N);
	v.resize(N);
	for(int i=0;i<N;i++){
		scanf("%d",&v[i]);
		if(MAX < v[i])
			MAX = v[i];
	}
	scanf("%d",&M);
	printf("%d",solve());
	return 0;
}
