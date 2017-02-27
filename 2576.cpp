#include <cstdio>
#include <climits>
#define MIN(x,y) ((x)>(y))?(y):(x)
using namespace std;
int main(){
	int sum=0;
	int min=INT_MAX;
	bool is_Exist=false;
	for(int i=0;i<7;i++){
		int temp;
		scanf("%d",&temp);
		if(temp%2==1){
			is_Exist=true;
			min=MIN(min,temp);
			sum+=temp;
		}
	}
	if(is_Exist)
		printf("%d\n%d",sum,min);
	else
		printf("-1");
	return 0;
}
