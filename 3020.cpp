#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
int N, H, ans=INT_MAX, cnt=0;
vector<int> A; // 석순.
vector<int> B; // 종유석.

int main(){
	scanf("%d %d",&N,&H);
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		if(i%2==0)
			A.push_back(temp);
		else
			B.push_back(temp);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for(int x=1;x<=H;x++){
		int sum=0;
		sum+=upper_bound(A.begin(), A.end(), A[N/2-1])-lower_bound(A.begin(), A.end(), x);
		sum+=upper_bound(B.begin(), B.end(), B[N/2-1])-lower_bound(B.begin(), B.end(), H-x+1);
		/*for(int i=0;i<N/2;i++){
			if(A[i] >= x)
				sum+=1;
			if(B[i] > (H-x))
				sum+=1;
		}*/
		if(sum < ans){
			ans = sum;
			cnt = 1;
		}
		else if(sum == ans){
			cnt++;
		}
		//printf("x : %d sum : %d ans : %d cnt : %d\n", x, sum, ans, cnt);
	}
	printf("%d %d",ans,cnt);
	return 0;
}
