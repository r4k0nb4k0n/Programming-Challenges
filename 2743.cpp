#include <cstdio>

using namespace std;

int main()
{
    char s[100];
    scanf("%s",s);
    int i=0;
    while(s[i] != '\0')
        i++;
    printf("%d",i);
    return 0;
}