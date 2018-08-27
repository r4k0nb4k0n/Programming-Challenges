#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int V; // 트리의 정점의 개수.
vector<vector<pair<int,int> > > tree;
// first는 다음 정점 번호, second는 가중치.
bool visited[100001]; // 방문 여부 확인 배열.

pair<int, int> solve(int root)
{
	queue<pair<int, int> > q;
	visited[root] = true;
	q.push(make_pair(root, 0));
	pair<int, int> ret;
	ret.first = -1;
	ret.second = -1;

	//BFS 탐색.
	while(!q.empty())
	{
		//큐의 front에서 현재 정점과 현재까지 거리의 합 불러옴.
		int now = q.front().first;
		int dist_now = q.front().second;
		q.pop();
		int length = tree[now].size();
		for(int i=0;i<length;i++)
		{
			//다음 정점과 다음 정점까지 거리의 합 구함.
			int next = tree[now][i].first;
			int dist_next = dist_now + tree[now][i].second;

			if(!visited[next])
			{
				visited[next] = true;
				q.push(make_pair(next,dist_next));
				// ret보다 dist_next가 더 크면.
				if(dist_next > ret.second)
				{
					ret.first = next;
					ret.second = dist_next;
				}
			}
		}
	}
	return ret;
}

int main(void)
{
	scanf("%d",&V);
	tree.resize(V+1);
	for(int i=1;i<=V;i++)
	{
		int N1, N2, D;
		scanf("%d",&N1);

		while(1)
		{
			scanf("%d",&N2);
			if(N2 != -1)
			{
				scanf("%d",&D);
				tree[N1].push_back(make_pair(N2,D));
				tree[N2].push_back(make_pair(N1,D));
			}
			else
				break;
		}
	}
	// 1에서 제일 먼 점과 그 거리를 저장.
	pair<int, int> result = solve(1); 
	int point = result.first;
	memset(visited,false,V+1);
	// 그 먼 점에서 가장 먼 점과 그 거리를 저장 => 답.
	result = solve(point);
	int answer = result.second;
	printf("%d",answer);
}