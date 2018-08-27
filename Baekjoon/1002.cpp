#include <iostream>
#define SQ2(x) ((x)*(x))
using namespace std;
struct circle{
	int x;
	int y;
	int r;

	int operator *(const circle &other) const{
		int d = SQ2(x-other.x) + SQ2(y-other.y);
		if(x == other.x && y == other.y){ // 중심 서로 같을 때
			if(r == other.r)
				return -1; // 반지름 서로 같을 때
			else
				return 0; // 반지름 서로 다를 때
		}
		else{ // 중심 서로 다를 때
			if(d == SQ2(r+other.r)) // 반지름의 합 == 중심 사이 거리
				return 1;
			else if(d > SQ2(r+other.r)) // 반지름의 합 > 중심 사이 거리
				return 0;
			else if(d == SQ2(r-other.r)) // 반지름의 차 == 중심 사이 거리
				return 1;
			else if(d < SQ2(r-other.r)) // 반지름의 차 < 중심 사이 거리
				return 0;
			else
				return 2;
		}
	}
};

int main(){
	int T;
	cin >> T;
	circle A, B;
	while(T--){
		cin >> A.x >> A.y >> A.r >> B.x >> B.y >> B.r;
		cout << A*B << "\n";
	}
	return 0;
}
