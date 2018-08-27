#include <iostream>
#include <cmath>
#include <string>
#include <map>

using namespace std;

map<string, int> R;
string first, second, third;
long result;

int main()
{
	R["black"] = 0;
	R["brown"] = 1;
	R["red"] = 2;
	R["orange"] = 3;
	R["yellow"] = 4;
	R["green"] = 5;
	R["blue"] = 6;
	R["violet"] = 7;
	R["grey"] = 8;
	R["white"] = 9;

	cin >> first >> second >> third;
	result = R[first] * 10 + R[second];
	result = result * (long)pow(10, R[third]);
	cout << result;

	return 0;
}
