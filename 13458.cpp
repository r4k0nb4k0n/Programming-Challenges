#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int main(){
	long long N, A[1000000], B, C, answer=0;
	// 최악의 경우 시험장 수 백만 * 응시자 수 백만 에다가 B, C == 1 ==> long long

	// 입력
	scanf("%lld",&N); // 시험장의 개수
	for(int i=0;i<N;i++) 
		scanf("%lld",&A[i]); // 각 시험장에 있는 응시자의 수
	scanf("%lld %lld",&B,&C); // B, C
	
	// 처리
	for(int i=0;i<N;i++){
		int student = A[i]; // 각 시험장에 있는 응시자 수 저장.
		int teacher = 0;
		if(student <= B){ // 총감독관 1명만으로 커버친다면
			teacher += 1;
			answer += teacher;
			continue; // 부감독관 생각하지않고 넘어가기
 		}
		else{ // 총감독관 1명만으로는 커버칠 수 없을 때
			teacher += 1;
			student -= B; // 총감독관 커버 수만큼 빼주고 부감독관 세기. 밑으로.
		}
		if(student % C != 0){ // 부감독관.
			teacher += (student/C) + 1;
			answer += teacher;
		}
		else{
			teacher += student/C;
			answer += teacher;
		}
	}
	printf("%lld",answer);
	return 0;
}
