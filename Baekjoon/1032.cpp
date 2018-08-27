#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<string> v;
	for(int i=0;i<N;i++){
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	string ans;
	int size=v[0].size();
	for(int i=0;i<size;i++){
		int j;
		bool is_Right=true;
		for(j=1;j<N;j++){
			if(v[0].at(i) != v[j].at(i)){
				is_Right=false;
				ans += "?";
				break;
			}
			else
				is_Right=true;
		}
		if(is_Right)
			ans+=v[0].at(i);
	}
	cout << ans;
	return 0;
}
