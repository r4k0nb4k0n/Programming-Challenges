#include <stdio.h>
// 형식 지정자를 이용한 방법
int main()
{
    int n,sum,temp;
    sum = 0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%1d",&temp); // 한 글자씩만 읽어들인다.
        sum = sum + temp;
    }
    printf("%d",sum);
    return 0;
}
