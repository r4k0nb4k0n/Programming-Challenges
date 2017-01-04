#include <stdio.h>
#include <string.h>
int main()
{
    char s[101];
    int idx;
    int small, big, number, space;
    while(gets(s) != 0)
    {
        idx = 0;
        small = big = number = space = 0;
        while(s[idx] != '\0')
        {
            if(s[idx] >= 'a' && s[idx] <= 'z')
                small++;
            else if(s[idx] >= 'A' && s[idx] <= 'Z')
                big++;
            else if(s[idx] >= '0' && s[idx] <= '9')
                number++;
            else if(s[idx] == ' ')
                space++;
            idx++;
        }
        printf("%d %d %d %d\n",small,big,number,space);
    }
    return 0;
}
