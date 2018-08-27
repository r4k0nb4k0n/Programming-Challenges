#include <cstdio>

using namespace std;

int main()
{
	char jaehwan[1002];
	char doctor[1002];

	scanf("%s",jaehwan);
	scanf("%s",doctor);
	int i=0;
	while((jaehwan[i] == doctor[i]) && jaehwan[i] != '\0' && doctor[i] != '\0')
		i++;

	if((jaehwan[i] == doctor[i]) || jaehwan[i] < doctor[i])
		printf("go");
	else
		printf("no");
	return 0;
}