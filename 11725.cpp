#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > graph;
bool visited[100001];
queue<int> q;
int parent[100001];

void BFS(int root)
{
	visited[root] = true;
	q.push(root);
	parent[root] = -1;

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
				parent[there] = now;
				q.push(there);
			}
		}
	}

}

int main()
{
	int N;
	scanf("%d",&N);

	graph.resize(N+1);

	for(int i=0;i<N-1;i++)
	{
		int u, v;
		scanf("%d %d",&u,&v);

		graph[u].push_back(v);
		graph[v].push_back(u);
		// 양방향...?
	}
	BFS(1);

	for(int i=2;i<=N;i++)
		printf("%d\n",parent[i]);


	return 0;
}