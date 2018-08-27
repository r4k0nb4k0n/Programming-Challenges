#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> angle(3);
	for(int i=0;i<3;i++)
		scanf("%d",&angle[i]);

	sort(angle.begin(),angle.end());

	if(angle[0] == angle[1] && angle[1] == angle[2])
		printf("Equilateral");
	else if((angle[0] + angle[1] + angle[2] == 180) && (angle[0] == angle[1] || angle[1] == angle[2]))
		printf("Isosceles");
	else if(angle[0] + angle[1] + angle[2] != 180)
		printf("Error");
	else
		printf("Scalene");

	return 0;
}