#include <stdio.h>
// 형식 지정자를 이용한 방법
// Using Type Identifier
int main()
{
    int n,sum,temp;
    sum = 0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%1d",&temp); // 한 글자씩만 읽어들인다. // Read ONE letter at ONE time.
        sum = sum + temp;
    }
    printf("%d",sum);
    return 0;
}
