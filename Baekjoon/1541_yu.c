#include <stdio.h>
int main(){
	int A,N,M=0;
    // A : 결과, N : 숫자 입력받는 변수, M : 연산자 '-' 마주침 여부 저장
	char O; // Operator 연산자.
	scanf("%d",&A); // 첫 숫자 입력받음.
	while(scanf("%c",&O)==1&&O!=10){ // 연산자 입력받았고, LR(Line Feed)가 아니라면
		if(O=='-') // 연산자 '-' 만났다면
			M=1; // 마주쳤다고 저장
		scanf("%d",&N); // 다음 숫자 저장.
		if(M==1) // 연산자 '-' 만났었다면
			A-=N; // 그 이후로 다 빼주기
		else
			A+=N; // 더해주기
	}
	printf("%d",A); // 정답 출력하기
	return 0;
}

// 소스참조
