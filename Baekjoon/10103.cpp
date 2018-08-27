#include <cstdio>
using namespace std;
int main(){
	int n;
	int a=100,b=100;
	scanf("%d",&n);
	while(n--){
		int i, j;
		scanf("%d %d",&i,&j);
		if(i<j)
			a-=j;
		else if(i>j)
			b-=i;
	}
	printf("%d\n%d",a,b);
	return 0;
}
