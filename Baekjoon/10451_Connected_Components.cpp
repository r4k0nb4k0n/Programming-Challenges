#include <iostream>
#include <vector>
#define SIZE 1001
using namespace std;

int T, V, cnt;
vector<vector<int> > adj(SIZE);
vector<bool> visited(SIZE);

void DFS(int now){
	visited[now] = true;
	int size = adj[now].size();
	for(int i=0;i<size;i++){
		int next = adj[now][i];
		if(!visited[next])
			DFS(next);
	}
}

int main(){
	cin >> T;
	while(T--){
		cin >> V;
		cnt = 0;
		for(int i=1;i<=V;i++)
			adj[i].clear();
		visited.assign(SIZE, false); // Initialization.
		for(int i=1;i<=V;i++){
			int head;
			cin >> head;
			adj[i].push_back(head); // Input.
		}
		for(int i=1;i<=V;i++){
			if(!visited[i]){
				cnt++; // Counting Connected Components.
				DFS(i);
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
