#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d",&N);
    
    for(int i=1;i<=N;i++)
    {
        if(i % 2 == 0)
            printf(" ");
        
        for(int j=1;j<=N;j++)
        {
            if(j == 1)
                printf("*");
            else
                printf(" *");
        }
        
        printf("\n");
    }
    
    return 0;
}