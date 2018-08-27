#include <iostream>
#include <vector>

using namespace std;

int n;
int answer=0;

int main(){
	cin >> n;
	while(n--){
		int numOfPos = 0;
		for(int i=0; i<3; i++){
			int tmp;
			cin >> tmp;
			numOfPos += tmp;
		}
		if(numOfPos >= 2)
			answer++;
	}
	cout << answer;
	return 0;
}
