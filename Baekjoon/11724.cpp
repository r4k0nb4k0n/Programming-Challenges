#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int matrix[1001][1001]; // 정점의 연결관계 행렬
bool visited[1001]; // 정점 방문 기록
bool started; // BFS 최소 한번 실행되었는지 여부
int cnt=1; // 최소한 1개의 연결 요소는 있다.
int N,M; // 정점의 개수 N, 간선의 개수 M

void BFS(int root)
{
	if(visited[root] == 0 && started == true)
	// 입력받은 정점 방문한 적 없는데 BFS가 최소 한번 이상 실행되었다면
	// 새로운 연결 요소를 발견!
	{
		cnt++; // 연결 요소 개수 1 증가.
		visited[root] = true; // 탐색했다고 표시해줌.
	}
	else
	// 한 연결 요소 안에서 탐색중이라는 것.
	{
		started = true; // BFS가 최소 한번 이상 실행되었다고 표시해줌.
		visited[root] = true; // 탐색했다고 표시해줌.
	}

	queue<int> q;
	q.push(root);

	while(!q.empty())
	{
		int now = q.front();
		q.pop();

		for(int i=1;i<=N;i++)
		if(!visited[i] && matrix[now][i] == 1)
		{
			visited[i] = true;
			q.push(i);
		}
	}
}

int main(void)
{
	
	scanf("%d %d",&N,&M); // 정점의 개수 N, 간선의 개수 M 입력받음.

	for(int i=1;i<=M;i++) // 관계 입력받음.
	{
		int u,v;
		scanf("%d %d",&u,&v);
		matrix[u][v] = matrix[v][u] = 1; // 양방향. 무방향.
	}

	for(int i=1;i<=N;i++) // 정점의 개수만큼 반복.
	{
		if(!visited[i]) // 이 정점을 탐색해본 적이 없다면
			BFS(i); // BFS ㄱㄱ.
	}

	printf("%d",cnt); // 연결 요소의 개수 출력.
}
