#include <cstdio>
#include <vector>
#include <algorithm> // reverse()
using namespace std;

int main() {
	int a, b;
	vector<int> list;
	for (int i = 1; i <= 20; i++) list.push_back(i); // 1~20 오름차순 배열 생성

	//입력 및 처리
	while (scanf("%d %d", &a, &b) == 2 && a != EOF && b != EOF) { // 구간 입력받기
		reverse(list.begin() + a - 1, list.begin() + b); // 카드 뒤집기 처리하기
	}

	//출력
	for (int i = 0; i<20; i++) printf("%d ", list[i]); // 하나씩 띄어쓰기로 출력하기

	return 0;
}
