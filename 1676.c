#include <stdio.h>
int main(){
	int n;
	int two = 0, five = 0;
	int i;
	scanf("%d",&n);
	for(i=2;i<=n;i*=2)
		two+=n/i;
	for(i=5;i<=n;i*=5)
		five+=n/i;
	printf("%d",(two<five)?two:five);
	return 0;
}
