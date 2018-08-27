#include <cstdio>
using namespace std;
long long int GCD(long long int x, long long int y){
	if(y==0)
		return x;
	return GCD(y, x%y);
}
int main(){
	long long int A, B;
	scanf("%lld %lld",&A,&B);
	printf("%lld",A*B/GCD(A,B));
	return 0;
}
