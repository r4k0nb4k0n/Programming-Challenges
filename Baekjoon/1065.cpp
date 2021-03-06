#include <cstdio>
int n; // 값을 입력받는 변수 ( 1 <= N <= 1,000 )
int cnt=0; // 한수의 개수를 저장하는 변수, 0으로 초기화
char buf[5]; // 한수 판정을 위한 문자열 출력 버퍼
int main(){
    scanf("%d", &n); // N 입력 받기
    if(1 <= n && n <= 99) cnt=n; // 1부터 99까지는 모두 한수이므로 한수의 개수가 곧 n이 된다
    else if(100 <= n && n <= 1000){
        cnt = 99; // 1부터 99까지는 모두 한수이므로 일단 99개는 먹고 들어간다
        if(n==1000) n--; // 1000은 한수가 아니므로 제외
        for(int i=100; i<=n; i++){ // 100부터 n까지 확인
            sprintf(buf, "%d", i);
            if(buf[0]-buf[1] == buf[1]-buf[2]) cnt++; // 등차수열이면 한수의 개수 1 증가
        }
    }
    printf("%d", cnt); // 한수의 개수 출력
    return 0;
}
