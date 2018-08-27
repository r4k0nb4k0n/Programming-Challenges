#include <stdio.h>
#include <iostream>

using namespace std;

int T,M,N,K;
// 테스트 케이스 개수 T
// 배추밭 가로 길이 M
// 배추밭 세로 길이 N
// 배추 위치 개수 K
bool field[50][50]; // 배추밭 배열.
bool visited[50][50]; // 방문 기록.
int cnt=0; // 지렁이 수
int x_move[4] = {0,0,1,-1}; // 상하좌우 x 좌표.
int y_move[4] = {1,-1,0,0}; // 상하좌우 y 좌표.

void DFS(int x,int y) // DFS 또는 BFS로 배추밭 탐색.
{
	for(int i=0;i<4;i++)
	{
		int x_next = x + x_move[i];
		int y_next = y + y_move[i];

		if(x_next>=0 && x_next<M && y_next>=0 && y_next<N)
		{
			if(!visited[x_next][y_next] && field[x_next][y_next] == true)
			// 탐색한 적이 없고, 배추가 있다면
			{
				visited[x_next][y_next] = true; // 탐색했다고 표시.
				DFS(x_next,y_next); // 다음 좌표로 DFS 재귀 호출.
			}
		}
	}
}

void search() // 입력받은 크기(M*N)만큼 배추 탐색.
{
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(!visited[i][j] && field[i][j] == true)
			// 탐색한 적이 없고, 배추가 있다면
			{
				visited[i][j] = true; // 탐색했다고 표시.
				cnt++; // 배추흰지렁이 마리수 1 증가.
				DFS(i,j); // 해당 좌표로 DFS 호출.
			}
		}
	}
}

void initialization() // 탐색 후 field, visited, cnt 초기화.
{
	cnt = 0;
	for(int i=0;i<50;i++)
	{
		for(int j=0;j<50;j++)
		{
			visited[i][j] = false;
			field[i][j] = false;
		}
	}
}

int main(void)
{
	scanf("%d",&T);
	
	for(int i=1;i<=T;i++)
	{
		scanf("%d %d %d",&M,&N,&K);
		for(int j=1;j<=K;j++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			field[x][y] = true;
		}
		search();
		printf("%d\n",cnt);
		initialization();
	}

	return 0;
}