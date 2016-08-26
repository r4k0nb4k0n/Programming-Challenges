#include <cstdio>
#include <vector>
#include <queue>
 
using namespace std;
int N; // 학생 수. 최대 32,000명.
int M; // 키를 비교한 회수. 최대 100,000번.
vector<int> indegree;
vector<vector<int> > graph;
 
void BFS(void)
{
    queue<int> q;
    for(int i=1;i<=N;i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        printf("%d ",now);
        int length = graph[now].size();
        for(int i=0;i<length;i++)
        {
            int next = graph[now][i];
            indegree[next]--;
            if(indegree[next]==0)
                q.push(next);
        }
    }
}
 
int main()
{
    scanf("%d %d",&N,&M);
    indegree.resize(N+1);
    graph.resize(N+1);
    while(M--)
    {
        int u, v;
        scanf("%d %d",&u,&v);
        graph[u].push_back(v); // u->v. 방향 그래프.
        indegree[v] += 1; // u->v 이므로 v에 들어오는 간선 1 증가.
    }
    BFS();
    printf("\n");
    return 0;
}