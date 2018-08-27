#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v(3);

	scanf("%d %d %d",&v[0],&v[1],&v[2]);

	sort(v.begin(),v.end());

	if(v[0] == v[1] && v[1] == v[2])
		printf("%d",10000+v[0]*1000);
	else if(v[0] != v[1] && v[1] != v[2] && v[2] != v[0])
		printf("%d",v[2] * 100);
	else
		printf("%d",1000+v[1]*100);

	return 0;
}