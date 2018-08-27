#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N; // 건물의 종류 수 N(1≤N≤500).
vector<vector<int> > graph; // 선행 관계를 저장하는 그래프.
vector<int> indegree; // 선입차수를 저장하는 리스트.
vector<int> time; // 건물을 짓는데 걸리는 시간을 저장하는 리스트.
vector<int> d; // 각 건물마다 최종적으로 걸리는 시간 저장하는 리스트.

void BFS()
{
	queue<int> q;
	for(int i=1;i<=N;i++)
	{
		if(indegree[i] == 0) // 선입차수가 0인 것부터
		{
			q.push(i); //큐에 푸시.
			d[i] = time[i];
		}
	}
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		int length = graph[now].size();
		for(int i=0;i<length;i++)
		{
			int next = graph[now][i]; // now->next
			indegree[next]--; // 선입차수 1씩 지워나감.
			if(d[next] < d[now] + time[next])
				d[next] = d[now] + time[next];
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
	time.resize(N+1);
	d.resize(N+1);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&time[i]);
		while(1)
		{
			int input;
			scanf("%d",&input);
			if(input == -1) // 입력의 끝엔 -1.
				break;
			else
			{
				graph[input].push_back(i); // input->i
				indegree[i]++; // i로 들어오는 선입차수 1 증가.
			}
		}
		
	}
	BFS(); // BFS 시작.
	for(int i=1;i<=N;i++)
		printf("%d\n",d[i]); // 결과값 출력.
	return 0;
}