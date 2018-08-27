#include <stdio.h>
int main()
{
    int n,sum,temp;
    sum = 0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%1d",&temp);
        sum = sum + temp;
    }
    printf("%d",sum);
    return 0;
}
