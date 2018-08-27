#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N; // 정점의 개수.
int M; // 간선의 개수.

vector<vector<int> > graph;
queue<int> q;

bool started;
bool visited[1001];

int cnt; // 연결 요소의 개수.

void BFS(int root)
{
	if(started && !visited[root])
	{
		cnt++;
		visited[root] = true;
	}
	else
	{
		started = true;
		visited[root] = true;
	}
	q.push(root);
	
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		int size = graph[now].size();

		for(int i=0;i<size;i++)
		{
			int there = graph[now][i];
			if(!visited[there])
			{
				visited[there] = true;
				q.push(there);
			}
		}

	}
}

int main(void)
{
	scanf("%d %d",&N,&M);
	graph.resize(N+1);

	for(int i=0;i<M;i++)
	{
		int u, v;
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
		// 양방향. 무방향.
	}

	for(int i=1;i<=N;i++)
		sort(graph[i].begin(),graph[i].end());

	for(int i=1;i<=N;i++)
		BFS(i);

	printf("%d",cnt);
	return 0;
}