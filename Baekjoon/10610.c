#include <stdio.h>
#include <string.h>
#define SIZE 100001
int main(){
    char s[SIZE];
    int cnt[10]={0}; // initializing list
    int i, sum=0, size;
    scanf("%s",s); // input
    size = strlen(s); // get the length of string.
    for(i=0;i<size;i++){
        cnt[s[i]-'0']++; // get the number of each number.
        sum+=s[i]-'0'; // get the sum of all number.
    }
    if(cnt[0]==0){
        printf("-1");
        return 0;
    } // 10의 배수가 아니라면
    if(sum%3!=0){
        printf("-1");
        return 0;
    } // 3의 배수가 아니라면
    
    for(i=9;i>=0;i--){
        for(;cnt[i]>0;cnt[i]--)
            printf("%d",i);
    }
    return 0;
}
