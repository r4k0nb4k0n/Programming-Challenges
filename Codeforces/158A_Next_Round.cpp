#include <cstdio>
using namespace std;
int main(){
	int n, k, p[50], cnt=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&p[i]);
	for(int i=0;i<n;i++){
		if(p[i]>=p[k-1] && p[i]>0)
			cnt++;
	}
	printf("%d",cnt);
	return 0;
}