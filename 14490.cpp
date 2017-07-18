#include <cstdio>
int gcd(int a, int b){
	if(a%b==0) return b;
	return gcd(b, a%b);
}
int main(){
	int n, m;
	scanf("%d:%d",&n,&m);
	int x = (n>m)?(gcd(n, m)):(gcd(m, n));
	printf("%d:%d",n/x,m/x);
	return 0;
}
