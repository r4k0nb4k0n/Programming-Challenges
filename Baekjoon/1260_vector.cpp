#include <cstdio>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int N; // 정점의 개수.
int M; // 간선의 개수.
int V; // 시작할 정점.
vector<vector<int> > graph;
queue<int> q;
bool visited[1001];

void DFS(int n)
{
	visited[n] = true;
	printf("%d ",n);
	int size = graph[n].size();
	// 해당 정점으로부터 나오는 간선의 개수.

	for(int i=0;i<size;i++)
	{
		int there = graph[n][i]; 
		// 벡터에 들어와 있다는 건 간선이 존재한다는 걸 의미.
		if(!visited[there]) // 방문한 적이 없다면.
			DFS(there);
	}
}

void BFS(int root)
{
	visited[root] = true;
	q.push(root);

	while(!q.empty())
	{
		int now = q.front();
		printf("%d ",now);
		q.pop();
		
		int size = graph[now].size();
		// 해당 정점으로부터 나오는 간선의 개수.

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
	scanf("%d %d %d",&N,&M,&V);
	graph.resize(N+1);

	for(int i=1;i<=M;i++)
	{
		int u, v;
		scanf("%d %d",&u,&v);
		// 양방향 간선.
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i=1;i<=N;i++)
		sort(graph[i].begin(),graph[i].end());

	DFS(V);
	memset(visited,false,sizeof(visited));
	printf("\n");
	BFS(V);

	return 0;
}