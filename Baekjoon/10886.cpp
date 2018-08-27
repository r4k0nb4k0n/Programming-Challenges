#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	int N; // 설문조사를 한 사람의 수.
	int cnt = 0; // 양수 -> cute , 음수 -> not cute.

	cin >> N;

	while(N--)
	{
		int temp;
		cin >> temp;

		if( temp == 1 )
			cnt++;
		else
			cnt--;
	}

	if( cnt > 0 )
		cout << "Junhee is cute!";
	else
		cout << "Junhee is not cute!";

	return 0;
}