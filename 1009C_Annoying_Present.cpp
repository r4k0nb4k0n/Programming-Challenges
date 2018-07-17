#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int n, m;
double maxAvg = numeric_limits<double>::min();

int dist(int x, int y){
	return (x>y) ? x-y : y-x;
}

int main(){
	cin >> n >> m;
	vector<int> present(n); fill(present.begin(), present.end(), 0);
	vector<int> x(m); vector<int> d(m);
	for(int i=0; i<m; i++){
		cin >> x[i] >> d[i];
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			fill(present.begin(), present.end(), 0);
			double avg = 0.0f;
			for(int k=0; k<n; k++){
				present[k] += x[i] + d[i] * dist(j, k);
				avg += (double)present[k];
			}
			avg /= (double)n;
			maxAvg = max(avg, maxAvg);
		}
	}
	cout << maxAvg;
	return 0;
}
