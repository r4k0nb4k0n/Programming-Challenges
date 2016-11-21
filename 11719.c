#include <stdio.h>
int main()
{
    char c;
    while( (c = getchar()) && c != EOF )
        printf("%c",c);
    return 0;
}
