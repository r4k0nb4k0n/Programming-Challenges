#include <stdio.h>
void solve(int q){
	if(q==0) return;
	if(q%2==0){
		solve(-(q/2));
		printf("0");
	}
	else{
		if(q>0)
			solve(-(q/2));
		else
			solve(-(q-1)/2);
		printf("1");
	}
}
int main(){
	int N;
	scanf("%d",&N);
	if(N==0) printf("0");
	else solve(N);
	return 0;
}
//http://blog.daum.net/rhaoslikesan/378
