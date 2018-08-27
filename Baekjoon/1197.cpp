#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int V, E; // V : 정점 개수, E : 간선 개수
vector<vector<pair<int, int> > > vec;
vector<bool> visited; // true : 방문함, false : 방문안함

int prim(int start) // 시작 정점을 정해줌
{
	int answer = 0;
	priority_queue<pair<int, int> > q; // 우선순위 큐 선언
	visited[start] = true;
	for(int i=0;i<vec[start].size();i++)
		q.push(make_pair(-vec[start][i].second, vec[start][i].first));
	// (-가중치, 다음 정점) -> 가중치가 가장 작은 순서대로 pop 된다.

	while(!q.empty())
	{
		int now = q.top().second;
		int nowcost = -q.top().first;
		q.pop();
		if(visited[now])
			continue;
		visited[now] = true;
		for(int i=0;i<vec[now].size();i++)
		{
			int next = vec[now][i].first;
			int nextcost = vec[now][i].second;
			if(!visited[next])
				q.push(make_pair(-nextcost,next));
		}
		answer += nowcost;
	}
	return answer;
}

int main()
{
	scanf("%d %d", &V, &E);
	vec.resize(V+1);
	visited.resize(V+1);
	
	for(int i=0;i<E;i++)
	{
		int start, end, cost;
		scanf("%d %d %d",&start,&end,&cost);
		// 양방향 혹은 무방향이므로 두 쪽 다 고려함.
		vec[start].push_back(make_pair(end, cost));
		vec[end].push_back(make_pair(start, cost));
	}
	printf("%d",prim(1));
	return 0;
}
