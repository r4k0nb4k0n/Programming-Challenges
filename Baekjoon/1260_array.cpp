#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

int N;// 정점의 개수.
int M;// 간선의 개수.
int V;// 탐색을 시작할 정점의 번호 V.
bool graph[1001][1001];
bool visited[1001];

void DFS(int n) // 깊이 우선 탐색.
{
	visited[n] = true; // 방문한 정점 표시.
	printf("%d ",n); // 방문한 정점 출력.

	for(int i=1;i<=N;i++)
	{
		// 간선이 존재하고 방문한 적이 없다면
		if(graph[n][i] == true && visited[i] == false)
		{
			DFS(i); // 재귀 호출로 DFS 탐색 시작.
		}
	}
}

void BFS(int root) // 너비 우선 탐색.
{
	visited[root] = true; // 첫 방문 표시.
	queue<int> q; // 큐 q 선언.
	q.push(root); // 큐에 첫 정점 삽입.

	while(!q.empty()) // 큐가 빌 때까지.
	{
		int now = q.front(); // 현재 방문한 정점을 큐에서 가지고 옴.
		printf("%d ",now); // 현재 정점 출력.
		q.pop(); // 큐에서 꺼내기.

		for(int i=1;i<=N;i++)
		{
			if(graph[now][i] == true && visited[i] == false)
			{
				visited[i] = true; // 방문 표시.
				q.push(i); // 큐에다 삽입.
			}
		}
	}
}

int main(void)
{
	scanf("%d %d %d",&N,&M,&V);
	for(int i=0;i<M;i++)
	{
		int u, v;
		scanf("%d %d",&u,&v);
		graph[u][v] = graph[v][u] = true; 
		// 입력으로 주어지는 간선은 양방향.
	}

	DFS(V);
	memset(visited,false,sizeof(visited)); //탐색 후 방문표시 배열 초기화.
	printf("\n");
	BFS(V);
	return 0;
}