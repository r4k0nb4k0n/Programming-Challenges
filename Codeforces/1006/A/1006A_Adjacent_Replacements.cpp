#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int m;

void adjacent_replace(vector<int> &v, int obj){
	int rep = (obj % 2) ? (obj + 1) : (obj - 1);
	for(int i=0; i<n; i++){
		if(v[i] == obj) v[i] = rep;
	}
}

int main(){
	cin >> n;
	m = INT_MIN;
	vector<int> u, v(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
		int odd = (v[i] % 2) ? v[i] : v[i]+1;
		int even = (v[i] % 2) ? v[i]+1 : v[i];
		if(find(u.begin(), u.end(), odd) == u.end()) u.push_back(odd);
		if(find(u.begin(), u.end(), even) == u.end()) u.push_back(even);
		m = max(m, v[i]);
	}
	sort(u.begin(), u.end());
	for(int i=0; i<u.size(); i++){
		adjacent_replace(v, u[i]);
	}
	for(int i=0; i<n; i++){
		cout << v[i] << " ";
	}
	return 0;
}
