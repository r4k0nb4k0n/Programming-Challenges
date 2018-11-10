#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a, b;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> a >> b;
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	transform(b.begin(), b.end(), b.begin(), ::tolower);
	
	int cmp = a.compare(b);
	if(cmp == 0) cout << "0";
	else if(cmp > 0) cout << "1";
	else cout << "-1";
	
	return 0;
}