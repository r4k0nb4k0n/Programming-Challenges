#include <cstdio>
using namespace std;
int a[2200][2200];
int cnt[3];
bool is_equal(int x, int y, int n){
	for(int i=x;i<x+n;i++)
		for(int j=y;j<y+n;j++)
			if(a[x][y] != a[i][j]) // 서로 다른게 나타나는 순간
				return false; // 모두 같은 수 아님. 거짓 리턴.
	return true; // 모두 같은 수임. 참 리턴.
}
void solve(int x, int y, int n){
	if(is_equal(x, y, n)){ // 기저조건. 모두 같은 수로 되어 있다면
		cnt[a[x][y]+1] += 1; // 해당 수의 종이의 개수 세기.
		return; // 재귀 종료.
	}
	int m = n/3;
	// 9개의 종이로 자르기.
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			solve(x + i*m, y + j*m, m);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]); // 입력
    solve(0,0,n); // 분할 정복
    for(int i=0;i<3;i++)
        printf("%d ",cnt[i]); // 결과 출력
    return 0;
}
