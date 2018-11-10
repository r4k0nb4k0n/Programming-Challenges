#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

int main(){
	cin >> n >> m;
	vector<bool> dangerous(m);
	fill(dangerous.begin(), dangerous.end(), true);
	for(int group=0; group<m; group++){
		int k;
		cin >> k;
		vector<bool> ricks(10001);
		vector<bool> mortys(10001);
		fill(ricks.begin(), ricks.end(), false);
		fill(mortys.begin(), mortys.end(), false);
		while(k--){
			int where;
			cin >> where;
			(where>0) ? ricks[where]=true : mortys[-where]=true;
		}
		int i;
		for(i=1; i<=n; i++){
			if(ricks[i] == mortys[i]) { dangerous[group] = false; break; }
		}
	}
	bool answer = true;
	for(int i=0; i<dangerous.size(); i++){
		answer &= dangerous[i];
	}
	if(answer) cout << "YES";
	else cout << "NO";
	return 0;
}
