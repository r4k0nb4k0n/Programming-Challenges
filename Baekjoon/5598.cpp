#include <cstdio>
#define MAX 1001
char s[MAX];
int i=0;
int main(){
    scanf("%s", s);
    while(s[i] != '\0') {
        s[i] = (s[i] - 'A' + 23) % 26 + 'A';
        i++;
    }
    printf("%s", s);
    return 0;
}
