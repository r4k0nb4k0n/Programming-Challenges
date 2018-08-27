#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

int w, h; // 지도의 너비 w, 지도의 높이 h. <= 50. width -> x, height -> y.
int map[50][50]; // land -> 0, sea -> 1.
bool visited[50][50]; // 방문 여부 표시.
// 동, 서, 남, 북, 북동, 남서, 북서, 남동
int x_move[8] = {1, -1, 0, 0, 1, -1, -1, 1}; 
int y_move[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int cnt; // 섬 개수.

void BFS(int x, int y) // (x, y)를 시작으로 BFS.
{
	visited[x][y] = true;
	queue<pair<int, int> > q; // BFS 위한 queue 선언. first -> x, second -> y.
	q.push(make_pair(x,y));
	
	while(!q.empty()) // queue가 빌 때까지 반복
	{
		int x_now = q.front().first; // 현재 x 좌표 저장.
		int y_now = q.front().second; // 현재 y 좌표 저장.
		visited[x_now][y_now] = true;
		q.pop();
		
		for(int i=0;i<8;i++) // 모든 방향으로 돌려봄.
		{
			int x_next = x_now + x_move[i];
			int y_next = y_now + y_move[i];
			
			if(0<=x_next && 0<=y_next && x_next< h && y_next < w)
			{
				if(map[x_next][y_next] != 0 && !visited[x_next][y_next])
				{
					visited[x_next][y_next] = true;
					q.push(make_pair(x_next,y_next));
				}
			}
		}
	}
}

int main(void)
{
	while(1)
	{
		scanf("%d %d",&w,&h);
		if(w <= 0 && h <= 0) // 무한반복 탈출조건.
			break;
		cnt = 0; // 섬 개수 초기화.
		memset(map,0,sizeof(map)); // 지도 초기화.
		memset(visited,false,sizeof(visited)); // 방문 여부 초기화.
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
				scanf("%d",&map[i][j]); // 섬 지도 입력.
		}
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(map[i][j] != 0 && !visited[i][j]) // 해당 좌표가 land이고 방문한 적이 없다면
				{ // 여기서부터 새로운 섬을 탐색시작하므로
					cnt++; // 섬 개수 1+.
					BFS(i,j); // BFS 시작.
				}
			}
		} // 지도 전체 다 훑음.
		printf("%d\n",cnt); // 섬 개수 출력.
	}
	return 0;
}
