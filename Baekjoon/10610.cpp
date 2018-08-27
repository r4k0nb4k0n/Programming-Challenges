#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;
int main(){
	priority_queue<char> a;
	string s;
	char c;
	int sum=0;
	while(scanf("%c",&c)==1&&c!=10){
		a.push(c); // 내림차순 정렬
	}
	while(!a.empty()){
		sum+=a.top()-'0'; // 각 자릿수 합 구함.
		s+=a.top(); // 한 숫자씩 붙임.
		a.pop();
	}
	if(s[s.length()-1]=='0' && sum%3==0) 
    // 끝이 0(10의 배수)이고 각 자릿수 합이 3의 배수이면
		cout << s;
	else
		printf("-1");
	return 0;
}
