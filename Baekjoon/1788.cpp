#include <cstdio>
#include <cstring>
#define ABS(x) ((x)>0)?(x):(-(x))

using namespace std;

int memo[1000001];

int fibonacci(int n){
	int &ret = memo[n];
	if(ret != -1)
		return ret;
	else
		ret = (fibonacci(n-1) + fibonacci(n-2))%1000000000;
	return ret;
}

int main(){
	int n, ans;
	scanf("%d",&n);
	memset(memo,-1,sizeof(memo));
	memo[0] = 0;
	memo[1] = 1;
	ans = fibonacci(ABS(n));
	if(n<0 && n%2==0)
		printf("-1\n");
	else if(n==0)
		printf("0\n");
	else
		printf("1\n");
	printf("%d",ans);
	return 0;
}
