#include <cstdio>
#include <cstring>
bool is_selfnum[10001]; // is_selfnum[x] : x의 셀프 넘버 여부 저장
int d; // d(n)의 결과값을 저장하는 변수
char buf[6]; // d(n)을 계산하기 위해 만든 문자열 출력 버퍼
int main(){
    memset(is_selfnum, true, sizeof(is_selfnum)); // 일단 모두 참으로 초기화
    for(int n=1;n<=10000;n++){ // 1부터 10000까지 반복
        d = n; // 생성자 대입, 1부터 10000까지 모두 생성자가 될 수 있음 
        sprintf(buf, "%d", n); // buf에 n을 문자열로 출력
        for(int i=0;buf[i]!='\0';i++)
            d = d + (buf[i]-'0'); // 문자를 숫자값으로 바꿔 d(n) 구함
        if(d <= 10000) // 배열 인덱스 초과 에러 방지
            is_selfnum[d] = false; // 셀프 넘버가 아닌 숫자 표시
        if(is_selfnum[n]) printf("%d\n", n); // 셀프 넘버인 숫자 표시
    }
    return 0;
}
