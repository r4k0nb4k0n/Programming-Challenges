#include <stdio.h>

int N; // 물건의 개수.
int M; // 미리 측정된 물건 쌍의 개수.
int scale_s[101][101]; // u > v
int scale_r[101][101]; // v > u
int visited_s[101];
int visited_r[101];

void DFS_s(int n)
{
	visited_s[n] = 1;

	for(int i=1;i<=N;i++)
	{
		if(!visited_s[i] && scale_s[n][i] == 1)
			DFS_s(i);
	}
}

void DFS_r(int n)
{
	visited_r[n] = 1;

	for(int i=1;i<=N;i++)
	{
		if(!visited_s[i] && scale_r[n][i] == 1)
			DFS_r(i);
	}
}

int main()
{
	scanf("%d",&N);
	scanf("%d",&M);

	int i,j;

	for(i=1;i<=M;i++)
	{
		int u, v;
		scanf("%d %d",&u,&v);

		scale_s[u][v] = 1; // u > v
		scale_r[v][u] = 1; // v > u
	}

	for(int i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			visited_s[j] = 0;
			visited_r[j] = 0;
		}
		int cnt = 0;

		DFS_s(i);
		DFS_r(i);

		for(int k=1;k<=N;k++)
		{
			if(visited_s[k] == 0 && visited_r[k] == 0)
				cnt++;
		}
		printf("%d\n",cnt);
	}
}