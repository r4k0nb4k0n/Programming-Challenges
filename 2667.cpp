#include <cstdio> // printf, scanf.
#include <vector> // 인접 리스트.
#include <queue> // BFS 탐색 시 사용하는 큐.
#include <algorithm> // 오름차순 정렬 sort.

using namespace std;

int N; // 지도의 크기. 5<=N<=25.
int map[25][25]; // 지도 저장할 배열.
bool visited[25][25]; // 방문 기록 남기는 논리 배열.
int x_move[4] = {1, -1, 0, 0};
int y_move[4] = {0, 0, 1, -1};
int group_num = -1;
vector<int> house_num;

void BFS(int x, int y)
{
	visited[x][y] = true;
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	
	while(!q.empty())
	{
		int x_now = q.front().first;
		int y_now = q.front().second;
		
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int x_next = x_now + x_move[i];
			int y_next = y_now + y_move[i];
			if(0<=x_next && 0<=y_next && x_next<N && y_next<N)
			{
				if(map[x_next][y_next] != 0 && !visited[x_next][y_next])
				{
					house_num[group_num]++;
					visited[x_next][y_next] = true;
					q.push(make_pair(x_next,y_next));
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d",&N); // 지도의 크기 N 입력받음.
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			scanf("%1d",&map[i][j]);
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(map[i][j] != 0 && !visited[i][j])
			{
				group_num++; // 단지수 1 증가.
				house_num.push_back(1);
				visited[i][j] = true;
				BFS(i,j); // 해당 지점으로 BFS 탐색 시작.
			}
		}
	}
	// 총 단지수 출력.
	printf("%d\n",group_num+1);
	// 단지수 오름차순 정렬 후 출력.
	sort(house_num.begin(),house_num.end());
	for(int i=0;i<=group_num;i++)
		printf("%d\n",house_num[i]);
	return 0;
}
