/* Programming-Challenges
 * Baekjoon
 * 11050
 * 2018-11-03 r4k0nb4k0n
 */

#include <iostream>
#define MAX 10
using namespace std;

int factorial[MAX + 1];

int binomial_coefficient(int n, int k){
	int a = factorial[n];
	int b = factorial[k];
	int c = factorial[n-k];
	return a / (b * c);
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// Calculate factorial up to 10.
	factorial[0] = factorial[1] = 1;
	for(int i=2; i<=MAX; i++) factorial[i] = factorial[i-1] * i;
	
	int n, k;
	cin >> n >> k;
	cout << binomial_coefficient(n, k);
	return 0;
}