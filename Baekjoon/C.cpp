#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int T;
int N, M;

bool visited[200001];
int res;
void dfs(vector<vector<int> > &graph, int n, int des, int length){
	if (n == des){
		res = max(res, length);
		return;
	}
	visited[n] = true;
	int len = graph[n].size();
	for (int i = 0; i < len; i++){
		int next = graph[n][i];
		if (!visited[next]){
			dfs(graph,next, des, length + 1);
		}
	}
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d %d",&N,&M);
		vector<vector<int> > graph(N+1);
		while (M--){
			int u, v;
			scanf("%d %d",&u,&v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int question;
		scanf("%d",&question);
		while (question--){
			int start, destination;
			scanf("%d %d",&start,&destination);
			res = 0;
			dfs(graph,start,destination,0);
			printf("%d\n", res + 1);
			memset(visited, false, N+1);
		}
	}
}