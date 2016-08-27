#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 도현이네 반 학생 수.

struct grade
{
	char name[101];
	int kor;
	int eng;
	int math;
};

vector<grade> list;

bool name_order(const char u_name[101],const char v_name[101])
{
	int i=0;
	while(u_name[i]==v_name[i])
	{
		i++;
	}
	if(u_name[i]<v_name[i])
		return true;
	else
		return false;
}

bool cmp(const grade &u, const grade &v)
{
	if( u.kor > v.kor ) // 1. 국어 점수가 감소하는 순서로
		return true;
	else if( (u.kor == v.kor) && (u.eng != v.eng) ) // 2. 국어 점수가 같으면
		return u.eng < v.eng; // 영어 점수가 증가하는 순서로
	else if( (u.kor == v.kor) && (u.eng == v.eng) && (u.math != v.math) ) // 3. 국어 점수와 영어 점수가 같으면
		return u.math > v.math; // 수학 점수가 감소하는 순서로
	else if( (u.kor == v.kor) && (u.eng == v.eng) && (u.math == v.math) ) // 4. 모든 점수가 같으면
		return name_order(u.name,v.name); // 이름이 사전 순으로 증가하는 순서로
	else
		return false;
}

int main()
{
	scanf("%d",&N);

	list.resize(N);

	for(int i=0;i<N;i++)
	{
		scanf("%s %d %d %d",list[i].name,&list[i].kor,&list[i].eng,&list[i].math);
	}

	sort(list.begin(),list.end(),cmp); // cmp 대로 퀵소트.

	for(int i=0;i<N;i++)
	{
		printf("%s",list[i].name);
		if(i<N)
			printf("\n");
	}

	return 0;

}