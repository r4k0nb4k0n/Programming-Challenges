#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;

int T;
string input;
int main(){
	cin >> T;
	getline(cin, input); // '\n' 비우기
	while(T--){
		getline(cin, input); // 띄어쓰기 포함한 문자열 한 줄 입력받기
		istringstream iss(input);
		// 띄어쓰기를 구분자로 파싱한 후 벡터에 집어넣기
		vector<string> token{istream_iterator<string>{iss}, istream_iterator<string>{}};
		for(int i=0; i<token.size(); i++){
			reverse(token[i].begin(), token[i].end());
			cout << token[i];
			if(i != token.size() - 1)
				cout << " ";
		}
		cout << "\n";
	}
	return 0;
}