#include <cstdio>
#include <math.h>
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d",&n,&m); // a^2 + b = n; a + b^2 = m;
    int cnt = 0;

    for(int a=0;a<10*sqrt(10);a++)
    {
        for(int b=0;b<10*sqrt(10);b++)
        {
            if((pow(a,2)+b==n) && (a+pow(b,2)==m))
                cnt++;
            else if((pow(a,2)+b>n) || (a+pow(b,2)>m))
                break;
        }
    }
    printf("%d",cnt);
    return 0;
}
