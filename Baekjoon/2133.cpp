#include <cstdio>
#include <cstring>
using namespace std;
int memo[31];
int f(int n){
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(n==2)
        return 3;
    
    int &ret = memo[n];
    if(ret!=-1)
        return ret;
    
    ret = 3*f(n-2);
    for(int k=4;k<=n;k+=2)
        ret += 2*f(n-k);
    return ret;
}
int main(){
    int n;
    scanf("%d",&n);
    memset(memo,-1,sizeof(memo));
    if(n%2==1)
        printf("0");
    else
        printf("%d",f(n));
    return 0;
}
