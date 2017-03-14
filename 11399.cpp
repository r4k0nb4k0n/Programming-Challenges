#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
int main(){
	int N; vector<int> v;
	cin >> N;
	while(N--){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	int sum=0;	
sort(v.begin(), v.end(), greater<int>()); // Descending order. 내림차순
	for(int i=0;i<v.size();i++){
		sum+=v[i]*(i+1);
	}
	cout << sum;
	return 0;
}
