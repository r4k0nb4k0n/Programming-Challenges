#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
	deque<int> circle;
	vector<int> answer;
	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		circle.push_back(i);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (j == M)
				answer.push_back(circle.front());
			else
				circle.push_back(circle.front());
			circle.pop_front();
		}
	}

	cout << "<";
	for (int i = 0; i < N; i++)
	{
		cout << answer[i];
		if (i != N - 1)
			cout << ", ";
	}
	cout << ">";

	return 0;
}
