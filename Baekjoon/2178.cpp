#include <stdio.h>
#include <iostream>
#include <queue>
#define FFLUSH while(getchar()!='\n')
 
using namespace std;
 
int N, M;
int miro[101][101];
bool visited[101][101];
int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };
 
struct point
{
    int x;
    int y;
    int time;
};
 
void BFS(int sx, int sy, int dx, int dy)
{
    visited[sx][sy] = true;
 
    queue<point> q;
 
    q.push({ sx, sy, 1 });
 
    while (!q.empty())
    {
        int now_x = q.front().x;
        int now_y = q.front().y;
        int time = q.front().time;
        q.pop();
 
        if (now_x == dx && now_y == dy){
            printf("%d\n", time);
        }

        for (int i = 0; i<4; i++)
        {
            int next_x = now_x + move_x[i];
            int next_y = now_y + move_y[i];
 
            if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= M)
            {
                if (!visited[next_x][next_y] && miro[next_x][next_y] == 1)
                {
                    visited[next_x][next_y] = true;
                    q.push({ next_x, next_y, time + 1 });
                }
            }
        }
    }
}
 
int main()
{
    scanf("%d %d", &N, &M);
    FFLUSH;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            char c;
            scanf("%c", &c);
            miro[i][j] = c - '0';
        }
        FFLUSH;
    }
 
    BFS(1, 1, N, M);
}