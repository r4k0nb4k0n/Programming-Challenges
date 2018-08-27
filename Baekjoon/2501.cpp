#include <cstdio>
#include <vector>
using namespace std;
int main(){
	vector<int> divisor;
	int N, K;
	scanf("%d %d",&N,&K);
	for(int i=1;i<=N;i++)
		if(N%i==0)
			divisor.push_back(i);
	if(divisor.size()<K)
		printf("0");
	else
		printf("%d",divisor[K-1]);
	return 0;
}
