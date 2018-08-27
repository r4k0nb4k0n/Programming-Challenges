#include <cstdio>
#include <cstring>
#define SIZE 1000001
bool is_Prime[SIZE];
void Eratos(){
	memset(is_Prime,true,SIZE);
	is_Prime[0] = is_Prime[1] = false;
	for(int i=2;i*i<=SIZE+1;i++)
		if(is_Prime[i])
			for(int j=i*i;j<=SIZE+1;j+=i)
				is_Prime[j] = false;
	return;
}
int main(){
	int n;
	Eratos();
	while(scanf("%d",&n) && n!=0){
		int i;
		for(i=3;i<=n;i+=2){
			if(is_Prime[i] && is_Prime[n-i]){
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
		}
		if(i>n)
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}
