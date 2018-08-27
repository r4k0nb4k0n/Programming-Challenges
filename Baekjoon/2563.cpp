#include <cstdio>
using namespace std;
bool field[101][101] = {false};
int main(){
	int N, x, y;
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&x,&y);
		for(int i=x;i<x+10;i++)
			for(int j=y;j<y+10;j++)
				field[i][j] = true;
	}
	int ans = 0;
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			if(field[i][j])
				ans++;
	printf("%d",ans);
	return 0;
}
