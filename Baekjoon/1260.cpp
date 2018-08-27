#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
 
using namespace std;
 
int N, M, V;
int matrix[1001][1001];
bool visited[1001];
 
void dfs(int n)
{
    visited[n] = true;
    printf("%d ", n);
 
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i] && matrix[n][i] == 1)
            dfs(i);
    }
}
 
void bfs(int root)
{
    visited[root] = true;
    queue<int> q;
 
    q.push(root);
 
    while (!q.empty())
    {
        int now = q.front();
        printf("%d ", now);
        q.pop();
 
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i] && matrix[now][i] == 1)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
 
int main()
{
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        matrix[u][v] = matrix[v][u] = 1;
    }
 
    dfs(V);
    printf("\n");
    memset(visited, false, 1001);
    bfs(V);
}