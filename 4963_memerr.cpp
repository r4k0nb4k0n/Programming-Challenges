#include <cstdio>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int w, h; // 지도의 너비 w, 지도의 높이 h. <= 50.
vector<vector<int> > map;
vector<vector<bool> > visited;
int x_move[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int y_move[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int cnt;

void BFS(int x, int y)
{
	visited[x][y] = true;
	queue<pair<int, int> > q;
	q.push(make_pair(x,y));
	
	while(!q.empty())
	{
		int x_now = q.front().first;
		int y_now = q.front().second;
		visited[x_now][y_now] = true;
		q.pop();
		
		for(int i=0;i<8;i++)
		{
			int x_next = x_now + x_move[i];
			int y_next = y_now + y_move[i];
			
			if(0<=x_next && 0<=y_next && x_next< w && y_next < h)
			{
				if(map[x_next][y_next] != 0 && !visited[x_next][y_next])
				{
					
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
		if(w <= 0 && h <= 0)
			break;
		cnt = 0;
		map.clear();
		visited.clear();
		map.resize(w);
		visited.resize(w);
		
		for(int i=0;i<w;i++)
		{
			for(int j=0;j<h;j++)
			{
				int temp;
				scanf("%d",&temp);
				map[i].push_back(temp);
				visited[i].push_back(false);
			}
		}
		for(int i=0;i<w;i++)
		{
			for(int j=0;j<h;j++)
			{
				if(map[i][j] != 0 && !visited[i][j])
				{
					cnt++;
					BFS(i,j);
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
