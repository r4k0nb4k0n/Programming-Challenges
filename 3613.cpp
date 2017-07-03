#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	char s[101];
	scanf("%s",s);
	bool is_upper = false;
	bool is_under = false;
	int size = strlen(s);
	if(('A' <= s[0] && s[0] <= 'Z') ||s[0] == '_' || s[size-1] == '_'){
		printf("Error!");
		return 0;
	}
	for(int i=0;i<size;i++){
		if(s[i] == '_'){
			is_under = true;
			if(i<=size-2 && s[i+1] == '_'){
				printf("Error!");
				return 0;
			}
		}
		if('A' <= s[i] && s[i] <= 'Z'){
			is_upper = true;
		}
	}
	if(is_upper && is_under){
		printf("Error!");
		return 0;
	}
	for(int i=0;i<size;i++){
		if(s[i]=='_') printf("%c",s[++i]-'a'+'A');
		else if('A'<=s[i] && s[i]<='Z') printf("_%c",s[i]-'A'+'a');
		else printf("%c",s[i]);
	}
	return 0;
}
