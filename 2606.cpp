#include <stdio.h>
#include <iostream> // cin
#include <vector> // 리스트
#include <algorithm> // sort(퀵소트)

using namespace std;

vector<vector<int> > graph; // 이중 인접 리스트.
vector<bool> infected; // 감염 흔적.

int cnt; // 감염된 컴퓨터 수 저장(컴퓨터 1 제외).

void DFS(int n)
{
	infected[n] = true;
	int size = graph[n].size();
	for(int i=0;i<size;i++)
	{
		int there = graph[n][i];
		if(!infected[there])
		{
			cnt++; // 처음 시작한 컴퓨터 1은 포함시키지 않는다.
			DFS(there);
		}
	}
}

int main()
{
	int N; // 컴퓨터의 수.
	int M; // 직접 연결되어 있는 컴퓨터 쌍의 수.

	cin >> N;
	cin >> M;

	graph.resize(N+1); // 0 제외, 1~N.
	infected.resize(N+1); // 0 제외, 1~N.

	for(int i=1;i<=M;i++)
	{
		int u, v;
		cin >> u;
		cin >> v;
		graph[u].push_back(v); // u->v
		graph[v].push_back(u); // v->u
	}

	for(int i=1;i<=N;i++)
		sort(graph[i].begin(),graph[i].end()); // 내림차순 정렬.

	DFS(1); // DFS 감염 시작.

	printf("%d\n",cnt); // 결과값 출력.
}