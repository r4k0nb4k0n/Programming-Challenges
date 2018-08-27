#include <stdio.h>
int main()
{
    char str[100001];
    int i=0, cnt=0, result=0;
    scanf("%s",str);
    while(str[i]!='\0')
    {
        if(str[i]=='(')
            cnt++;
        else
        {
            cnt--;
            if(str[i-1]=='(') // 레이저라면
                result += cnt;
            else // 파이프의 끝이라면
                result++; // 닫혀서 잘려진 개수 추가
        }
        i++;
    }
    printf("%d",result);
    return 0;
}
