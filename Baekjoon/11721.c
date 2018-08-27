#include <stdio.h>
// 형식 지정자 이용
// Using Type Identifier
int main()
{
    char s[101];
    while(scanf("%10s",s) == 1) // 10글자씩 읽어들인다. // 10 letters at ONE time
		printf("%s\n",s);
    return 0;
}
