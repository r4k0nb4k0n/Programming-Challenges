#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main(void)
{
	int cnt; // N의 진짜 약수의 개수.

	scanf("%d",&cnt);
	v.resize(cnt);

	for(int i=0;i<cnt;i++)
		scanf("%d",&v[i]);
	// 어떤 수 N의 진짜 약수가 모두 주어진다 했으므로
	sort(v.begin(),v.end()); // 오름차순 정렬 후 

	printf("%d",v[0]*v[cnt-1]); // 맨 처음과 맨 끝의 곱이 N.
	return 0;
}