#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N; // 수행해야 할 작업 N개 (3 <= N <= 10000).
vector<vector<int> > graph; // 작업들의 선행관계 저장.
vector<int> indegree; // 작업들의 진입차수 저장.
vector<int> work; // 작업에 걸리는 시간 저장.
vector<int> d;

void BFS()
{
	queue<int> q;
	for(int i=1;i<=N;i++)
	{
		if(indegree[i] == 0) // 처음에 진입차수가 0이면
		{
			q.push(i); // 맨 위 정점이므로 큐에 푸시.
			d[i] = work[i];
		}
		
	}
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		int length = graph[now].size();
		for(int i=0;i<length;i++)
		{
			int next = graph[now][i];
			indegree[next]--;
			if(d[next] < d[now] + work[next]) // 시간이 가장 오래 걸리는 작업 기준이기 때문에
				d[next] = d[now] + work[next];
			if(indegree[next] == 0)
				q.push(next);
		}
	}
}

int main()
{
	scanf("%d",&N);
	graph.resize(N+1);
	indegree.resize(N+1);
	work.resize(N+1);
	d.resize(N+1);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&work[i]); // 해당 작업에 걸리는 시간.
		int cnt;
		scanf("%d",&cnt); // 그 작업에 대해 선행 관계에 있는 작업들의 개수.
		while(cnt--)
		{
			int temp;
			scanf("%d",&temp);
			graph[temp].push_back(i); // 선행 관계에 있는 작업들의 번호가 주어짐. // temp와 i의 순서 헷갈리지 말기.
			indegree[i]++; // 진입차수 1 증가.
		}
	}
	BFS();
	sort(d.begin(),d.end());
	printf("%d",d[N]);
	return 0;
}