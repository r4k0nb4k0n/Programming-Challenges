#include <iostream>

using namespace std;
typedef unsigned long long ull;

int n, m, a;
ull answer = 1;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m >> a;
	answer *= (n % a == 0) ? (n / a) : (n / a) + 1;
	answer *= (m % a == 0) ? (m / a) : (m / a) + 1;
	
	cout << answer << "\n";
	
	return 0;
}