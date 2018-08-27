#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int n; // 전체 사람의 수
int obj_1,obj_2; // 촌수를 계산해야 하는 서로 다른 두 사람의 번호
int m; // 부모 자식들 간의 관계의 개수
int matrix[101][101]; // 부모 자식들 간의 관계 행렬
bool visited[101]; // 탐색 기록
bool started; // BFS 시작 여부
int now,cnt; // now : 현재 조회하는 사람 번호 , cnt : 촌수
struct point // 구조체 point 선언
{
	int obj; // 조회할 사람 번호
	int cnt; // 계산되어진 촌수
};
queue<point> q; // 구조체 point 기반 큐 q 선언

void BFS(int start)
{
	visited[start] = true; // 처음 사람 탐색 기록 남김.
	q.push({start,0}); // q에 처음 사람과 촌수 0 push.

	while(!q.empty()) // q가 빌 때까지 반복.
	{
		now = q.front().obj;
		// 현재 조회하는 사람 번호를 q에서 가져오기.
		cnt = q.front().cnt;
		// 현재까지 계산한 촌수를 q에서 가져오기.
		q.pop();
		// now,cnt에 정보를 가져왔으므로 q에서 pop.

		if(now == obj_2) 
		// 현재 조회하는 사람 번호가 원하던 번호에 도달했다면
			printf("%d",cnt);
			// 촌수 출력.
		else if(started && !visited[obj_2] && cnt == 0)
		// BFS 최소 한번 이상 실행되었고
		// 원하던 사람 번호에 도달한 적이 없으며 
		// 촌수도 세어지지 않았다면
		// 두 사람의 친척 관계가 전혀 없다.
			printf("-1");

		started = true;
		// BFS가 최소 한번 이상 실행되었다는 것을 표시하는 bool.
		
		for(int i=1;i<=n;i++) // BFS
		{
			if(!visited[i] && matrix[now][i] == 1)
			{
				visited[i] = true;
				q.push({i,cnt+1});
			}
		}
	}

	//BFS 탐색이 끝난 후에도 

	if(!visited[obj_2]) 
	// 원하던 사람 번호에 도달한 적이 없다면
	// 두 사람의 친척 관계가 전혀 없다.
		printf("-1");

}
int main()
{
	scanf("%d",&n); // 전체 사람의 수 입력받음.
	scanf("%d %d",&obj_1,&obj_2); // 촌수 계산할 서로 다른 두 사람의 번호 입력받음.
	scanf("%d",&m); // 부모 자식들 간의 관계의 개수 입력받음.

	for(int i=1;i<=m;i++) // 관계의 개수만큼 반복함.
	{
		int u,v;
		scanf("%d %d",&u,&v);
		matrix[u][v] = matrix[v][u] = 1;
		// 촌수세기 위해서는 '상하'관계가 아니라 그냥 서로 연결되어있음을 나타내줘야 함.
	}

	BFS(obj_1);
}