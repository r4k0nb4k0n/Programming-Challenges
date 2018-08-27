#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int sum=0;
	vector<int> n;
	for(int i=0;i<5;i++){
		int temp;
		scanf("%d",&temp);
		sum+=temp;
		n.push_back(temp);
	}
	sort(n.begin(), n.end());
	printf("%d\n%d",sum/5,n[2]);
	return 0;
}
