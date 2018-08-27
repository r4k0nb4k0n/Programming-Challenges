#include <stdio.h> // 기본 입출력 포함.
#include <iostream> // 
#include <stack> // C++ STL 라이브러리에서 Stack 헤더파일 포함.
#include <string> // String 헤더 파일 포함. string 문자열 변수 사용 가능.

using namespace std;

int main(void)
{
	int N; // 키로거 입력 횟수 받는 변수.
	int i, j;
	
	int cnt; // 글자수 카운트.
	//int rem; // cnt 백업.
	string input;
	stack<char> left;
	stack<char> right;
	string output;

	cin >> N; // 횟수 입력.

	for(i=1;i<=N;i++) // 입력된 횟수만큼 반복.
	{
		j = 0; // input 주소 초기화.
		cnt = 0; // 글자수 카운트 초기화.

		cin >> input; // 키로깅 입력받음.

		while(input[j] != '\0') // 널 문자 나올때까지 읽어들임.
		{
			if(input[j] == '-') // Backspace.
			{
				if(!left.empty()) // 왼쪽 스택에 입력된 것이 있다면.
				{
					left.pop();
					cnt--; // 글자수 1 감소.
				}
				
			}
			else if(input[j] == '<') // 왼쪽으로 커서 이동.
			{
				if(left.empty() == 0) // 왼쪽 스택에 입력된 것이 있다면.
				{
					right.push(left.top());
					left.pop();
				}
			}
			else if(input[j] == '>') // 오른쪽으로 커서 이동.
			{
				if(right.empty() == 0) // 오른쪽 스택에 입력된 것이 있다면.
				{
					left.push(right.top());
					right.pop();
				}
			}
			else // Backspace와 커서 이동 제외한 나머지 글자.
			{
				left.push(input[j]); // 왼쪽 스택에 글자 입력.
				cnt++; // 글자수 1 증가.
			}

			j++; // 다음 글자로 넘어가기.
		}
		
		//rem=cnt; // cnt 값을 rem에 백업.
		
		while(left.empty() == 0) // 왼쪽 스택이 비워질 때까지.
		{
			right.push(left.top()); // 왼쪽 스택 값을 오른쪽 스택에 push.
			left.pop();
		}
		
		/*while(right.empty() == 0) // 오른쪽 스택이 비워질 때까지.
		{
			output[--cnt] = right.top(); // output에 거꾸로 입력.
			right.pop();
		}*/

		j = 0;

		while(right.empty() == 0)
		{
			output[j] = right.top();
			right.pop();
			j++;
		}
		

		/*
		for(j=rem-1;j>=0;j--)
			printf("%c",output[j]);

		printf("\n");
		*/

		for(j=0;j<cnt;j++)
			printf("%c",output[j]);

		printf("\n");
	}
}