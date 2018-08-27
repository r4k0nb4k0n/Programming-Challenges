#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double x, y, c;
double solve(){
	double low=0.0, high=min(x,y), mid;
	for(int i=0;i<10000;i++){
		mid = (low+high)/2.0;
		double d = mid;
		double h1 = sqrt(x*x-d*d);
		double h2 = sqrt(y*y-d*d);
		double h = (h1*h2)/(h1+h2);
		if(h>c) low = mid;
		else high = mid;
	}
	return low;
}
int main(){
	while(scanf("%lf %lf %lf",&x,&y,&c) == 3)
		printf("%.3lf\n",solve());
	return 0;
}
