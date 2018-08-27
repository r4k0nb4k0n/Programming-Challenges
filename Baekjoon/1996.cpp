#include <iostream>
#include <cstring>
#define SIZE 1000
using namespace std;
// 상, 하, 좌, 우, 좌상, 우상, 좌하, 우하
int move_r[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; 
int move_c[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int main(){
	int map[SIZE][SIZE], n;
	memset(map, 0, sizeof(map));
	cin >> n;
	for(int row=0;row<n;row++){
		for(int col=0;col<n;col++){
			char c;
			cin >> c;
			if(c=='.') continue; // 지뢰가 없을 시 통과
			int val = c-'0';
			map[row][col] = -1; // 지뢰 표시
			for(int i=0;i<8;i++){ // 그 칸과 인접해있는 8개의 칸에 지뢰 개수 더해주기
				int next_r = row + move_r[i];
				int next_c = col + move_c[i];
				if((0<=next_r && next_r<n) && (0<=next_c && next_c<n)){
					if(map[next_r][next_c] != -1)
						map[next_r][next_c] += val;
				} // map 범위 안에서만
			}
		}
	}
	
	for(int row=0;row<n;row++){
		for(int col=0;col<n;col++){
			if(map[row][col] == -1) // 지뢰는 "*"로 출력
				cout << "*";
			else if(map[row][col] >= 10) // 10 이상인 경우에는 'M'(Many)으로 출력
				cout << "M";
			else
				cout << map[row][col];
		}
		cout << "\n"; // N개의 줄에 걸쳐서 완성된 지뢰 찾기 map을 출력한다.
	}
	
	return 0;
}
