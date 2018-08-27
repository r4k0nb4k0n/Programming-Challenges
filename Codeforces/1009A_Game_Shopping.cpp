#include <iostream>
#include <queue>

using namespace std;

int n, m;
queue<int> c;
queue<int> a;
int input;

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> input;
		c.push(input);
	}
	for(int i=0; i<m; i++){
		cin >> input;
		a.push(input);
	}
	while(!a.empty() && !c.empty()){
		if(c.front() <= a.front()){
			c.pop();
			a.pop();
		}
		else c.pop();
	}
	cout << m-a.size();
	return 0;
}
