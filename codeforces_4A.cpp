#include <cstdio>
using namespace std;
int main(){
	int w;
	bool ans = false;
	scanf("%d",&w);
	for(int i=1;i<w;i++){
		if(i%2==0 && (w-i)%2==0)
			ans = true;
	}
	if(ans) printf("YES");
	else	printf("NO");
	return 0;
}