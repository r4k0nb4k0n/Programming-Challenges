#include <stdio.h>
#include <iostream>
#include <queue>
#define FFLUSH while(getchar()!='\n')

using namespace std;

int l,sx,sy,dx,dy;
bool visited[301][301];
struct point
{
	int x;
	int y;
	int step;
};
int move_x[8] = {1,2,2,1,-1,-2,-2,-1};
int move_y[8] = {2,1,-1,-2,-2,-1,1,2};

int BFS(int sx,int sy,int dx,int dy)
{
	visited[sx][sy] = true;

	queue<point> q;

	q.push({sx,sy,0});

	while(!q.empty())
	{
		int now_x = q.front().x;
		int now_y = q.front().y;
		int step = q.front().step;
		q.pop();

		if(now_x == dx && now_y == dy)
			return step;

		for(int i=0;i<8;i++)
		{
			int next_x = now_x + move_x[i];
			int next_y = now_y + move_y[i];

			if(next_x >= 0 && next_x < l && next_y >= 0 && next_y < l)
			{
				if(!visited[next_x][next_y])
				{
					visited[next_x][next_y] = true;
					q.push({next_x,next_y,step+1});
				}
			}
		}
	}

}

int main(void)
{
	int N;
	scanf("%d",&N);

	for(int i=1;i<=N;i++)
	{
		scanf("%d",&l);
		scanf("%d %d",&sx,&sy);
		scanf("%d %d",&dx,&dy);
		int ans = BFS(sx,sy,dx,dy);
		printf("%d\n",ans);
		
		for(int j=0;j<301;j++)
		{
			for(int k=0;k<301;k++)
				visited[j][k] = false;
		}
		step = 0;
	}
}