#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int T;
int N, M;
vector<vector<int> > graph;
bool visited[200001];
int res;
void dfs(int n,int des,int length){
	if (n == des){
		res = max(res, length);
		return;
	}
	visited[n] = true;
	int len = graph[n].size();
	for (int i = 0; i < len; i++){
		int next = graph[n][i];
		if (!visited[next]){
			dfs(next, des, length + 1);
		}
	}

}
int main(){
	cin >> T;
	while (T--){
		cin >> N; cin >> M;
		graph.clear();
		graph.resize(N + 1);
		while (M--){
			int u, v;
			cin >> u; cin >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int question;
		cin >> question;
		while (question--){
			int start, destination;
			cin >> start >> destination;
			res = 0;
			dfs(start,destination,0);
			printf("%d\n", res + 1);
			memset(visited, false, sizeof(visited));
		}
	}
}
