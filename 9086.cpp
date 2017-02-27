#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	char s[1000];
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		printf("%c%c\n",s[0],s[strlen(s)-1]);
	}
	return 0;
}
