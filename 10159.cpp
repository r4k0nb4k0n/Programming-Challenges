#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int N; // 물건의 개수.
int M; // 미리 측정된 물건 쌍의 개수.
bool scale_s[101][101]; // u > v
bool scale_r[101][101]; // v > u
bool visited_s[101];
bool visited_r[101];

void DFS_s(int n)
{
	visited_s[n] = true;

	for(int i=1;i<=N;i++)
	{
		if(!visited_s[i] && scale_s[n][i] == true)
			DFS_s(i);
	}
}

void DFS_r(int n)
{
	visited_r[n] = true;

	for(int i=1;i<=N;i++)
	{
		if(!visited_s[i] && scale_r[n][i] == true)
			DFS_r(i);
	}
}

int main()
{
	scanf("%d",&N);
	scanf("%d",&M);

	for(int i=1;i<=M;i++)
	{
		int u, v;
		scanf("%d %d",&u,&v);

		scale_s[u][v] = true; // u > v
		scale_r[v][u] = true; // v > u
	}

	for(int j=1;j<=N;j++)
	{
		memset(visited_s,false,101);
		memset(visited_r,false,101);
		int cnt = 0;
		DFS_s(j);
		DFS_r(j);

		for(int k=1;k<=N;k++)
		{
			if(visited_s[k] == false && visited_r[k] == false)
				cnt++;
		}
		printf("%d\n",cnt);
	}
}