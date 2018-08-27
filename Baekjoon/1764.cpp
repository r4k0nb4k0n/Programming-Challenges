#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int N, M, cnt=0;
	string temp;
	vector<string> list, result;

	cin >> N >> M;

	for (int i = 0; i < N + M; i++)
	{
		cin >> temp;
		list.push_back(temp);
	}

	sort(list.begin(), list.end());

	for (int i = 1; i < N + M; i++)
	{
		if (list[i - 1].compare(list[i]) == 0)
		{
			cnt++;
			result.push_back(list[i]);
		}
	}

	cout << cnt << "\n";

	for (int i = 0; i < cnt; i++)
		cout << result[i] << "\n";

	return 0;
}
