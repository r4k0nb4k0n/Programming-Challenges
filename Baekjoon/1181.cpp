#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct WORD{
	char word[51];
	int length;
};

bool cmp(const WORD &a, const WORD &b)
{
	if (a.length < b.length)
		return true;
	else if (a.length == b.length)
		return strcmp(a.word, b.word) < 0;
	return false;
}

int main()
{
	vector<WORD> LIST;
	int N, i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		WORD temp;
		scanf("%s", temp.word);
		temp.length = strlen(temp.word);
		LIST.push_back(temp);
	}
	sort(LIST.begin(), LIST.end(), cmp);
	i = 0;
	printf("%s\n", LIST[i].word);
	for (i = 1; i < N; i++)
	{
		if (strcmp(LIST[i - 1].word, LIST[i].word) == 0)
			continue;
		else
			printf("%s\n", LIST[i].word);
	}
	return 0;
}
