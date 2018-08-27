#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char N[100];
	int B, len;
	int result = 0;
	scanf("%s",N);
	len = strlen(N);
	scanf("%d",&B);
	for(int i=0;i<len;i++)
	{
		if('A'<=N[len-i-1] && N[len-i-1]<='Z')
			result += (N[len-i-1]-'A'+10) * (int)(pow(B,i));
		else
			result += (N[len-i-1]-'0') * (int)(pow(B,i));
	}
	printf("%d",result);
	return 0;
}
