#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int,int> > node;

void preorder(int now)
{
	if(now == 0)
		return;
	// 기저조건.

	printf("%c",now + 'A' - 1);
	preorder(node[now].first);
	preorder(node[now].second);
	return;
}

void inorder(int now)
{
	if(now == 0)
		return;
	// 기저조건.

	inorder(node[now].first);
	printf("%c",now + 'A' - 1);
	inorder(node[now].second);
	return;
}

void postorder(int now)
{
	if(now == 0)
		return;
	// 기저조건.

	postorder(node[now].first);
	postorder(node[now].second);
	printf("%c",now + 'A' - 1);
	return;
}

// A = 65
int main()
{
	int N; // 이진 트리의 노드의 개수.
	char me,left,right;

	scanf("%d",&N);

	node.resize(N+1);

	for(int a=1;a<=N;a++)
	{
		scanf(" %1c %1c %1c",&me,&left,&right);
		me = me - 'A' + 1;
		if(left != '.')
			node[me].first = left -'A' + 1;
		if(right != '.')
			node[me].second = right - 'A' + 1;
		if(left == '.')
			node[me].first = 0;
		if(right == '.')
			node[me].second = 0;
	}

	preorder(1);
	printf("\n");
	inorder(1);
	printf("\n");
	postorder(1);

	return 0;
}