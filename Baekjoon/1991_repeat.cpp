#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int,int> > node;
// first는 왼쪽. right는 오른쪽.

void preorder(int now)
{
	if(now == 0)
		return;

	printf("%c",now+'A'-1);
	preorder(node[now].first);
	preorder(node[now].second);

	return;
}

void inorder(int now)
{
	if(now == 0)
		return;

	inorder(node[now].first);
	printf("%c",now+'A'-1);
	inorder(node[now].second);

	return;
}

void postorder(int now)
{
	if(now == 0)
		return;

	postorder(node[now].first);
	postorder(node[now].second);
	printf("%c",now+'A'-1);

	return;
}

int main(void)
{
	int N; // 이진 트리의 노드의 개수.
	scanf("%d",&N);

	node.resize(N+1);

	for(int i=0;i<N;i++)
	{
		char parent, left, right;
		scanf(" %c %c %c",&parent,&left,&right);

		if( left != '.' )
			node[parent-'A'+1].first = left - 'A' + 1;
		if( right != '.' )
			node[parent-'A'+1].second = right - 'A' + 1;
		if( left == '.' )
			node[parent-'A'+1].first = 0;
		if( right == '.' )
			node[parent-'A'+1].second = 0;
	}
	preorder(1);
	printf("\n");
	inorder(1);
	printf("\n");
	postorder(1);

	return 0;
}