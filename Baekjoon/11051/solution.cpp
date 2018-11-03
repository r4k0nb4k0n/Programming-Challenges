/* Programming-Challenges
 * Baekjoon
 * 11051
 * 2018-11-04 r4k0nb4k0n
 */

#include <iostream>
#include <cstring>
#define MAX 1000
#define MOD 10007
using namespace std;

long long memo[MAX+1][MAX];

int binomial_coefficient(int n, int k){
	if(k > n-k) return binomial_coefficient(n, n-k);
	
	# Base condition
	if(k == 0 || n == k) return 1;
	
	# Memoization
	long long& ret = memo[n][k];
	if(ret != -1) return ret;
	
	# Pascal's rule
	ret = (binomial_coefficient(n-1, k-1) % MOD + binomial_coefficient(n-1, k) % MOD) % MOD;
	// cout << n << " " << k << " " << ret << "\n";
	return ret % MOD;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	memset(memo, (long long)-1, sizeof(memo));
	
	int n, k;
	cin >> n >> k;
	cout << binomial_coefficient(n, k);
	return 0;
}