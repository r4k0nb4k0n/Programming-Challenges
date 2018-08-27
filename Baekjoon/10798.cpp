#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	char s[5][16];
	memset(s,'\0',sizeof(s));
	for(int i=0;i<5;i++)
		scanf("%s",s[i]);
	for(int i=0;i<16;i++){
		for(int j=0;j<5;j++){
			if(s[j][i]!='\0')
				printf("%c",s[j][i]);
		}
	}
	return 0;
}
