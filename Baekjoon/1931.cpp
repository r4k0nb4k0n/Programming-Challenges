#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n, m=-1, cnt=0; // n : 회의의 수, m : 가장 나중인 끝 시간 저장, cnt : 최대 사용가능한 회의 수
	vector<pair<int, int> > v;
	// .first : 끝 시간, .second : 시작 시간
	cin >> n; // 입력 받음
	for(int i=0;i<n;i++){
		pair<int, int> temp;
		cin >> temp.second >> temp.first;
		v.push_back(temp);
	}
	sort(v.begin(), v.end()); // 끝 시간을 우선으로 오름차순 정렬
	for(int i=0;i<n;i++){
		if(v[i].second>=m){ 
			// 가장 나중인 끝 시간 다음으로 시작 시간이 나타난다면
			cnt++;
			m = v[i].first; // 가장 나중인 끝 시간 갱신.
		}
	}
	cout << cnt; // 결과값 출력.
	return 0;
}
