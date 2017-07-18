#include <cstdio>
int main(){
	char s[101];
	scanf("%s",s);
	for(int i=0;s[i]!='\0';i++){
		if('A'<=s[i] && s[i]<='Z') printf("%c",s[i]);
	}
	return 0;
}
