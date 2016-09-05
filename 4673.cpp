#include <cstdio>
#include <string.h>

using namespace std;

bool is_SelfNum[10001];

void self_number()
{
	for(int i=1;i<=10000;i++)
	{
		int n = i;
		char each_num[7];
		sprintf(each_num,"%d",n);
		int idx;
		idx = 0;
		while(each_num[idx] != '\0')
		{
			n = n + each_num[idx] - 48; // '0'의 AsCII CODE == 43
			if(n > 10000)
				break;
			idx++;
		}
		is_SelfNum[n] = false;
	}
	for(int i=1;i<=10000;i++)
	{
		if(is_SelfNum[i] == true)
			printf("%d\n",i);
	}
}

int main()
{
	// no input.
	memset(is_SelfNum,true,sizeof(is_SelfNum));
	self_number();
	
	return 0;
}
