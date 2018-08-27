#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    char s[100];
    int a;
    scanf("%s", s);
    if (s[0] == '0')
    {
        if (s[1] == 'x') // hex
        {
            a = strtol(s, NULL, 16);
            printf("%d", a);
        }
        else // oct
        {
            a = strtol(s, NULL, 8);
            printf("%d", a);
        }
    }
    else // dec
    {
        a = atoi(s);
        printf("%d", a);
    }
    return 0;
}
