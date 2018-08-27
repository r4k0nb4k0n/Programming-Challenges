#include <stdio.h>
int main(){
	int T, s, n, q, p;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&s);
		scanf("%d",&n);
		while(n--){
			scanf("%d %d",&q,&p);
			s+=q*p;
		}
		printf("%d\n",s);
	}
	return 0;
}
