#include <iostream>
#include <utility> // pair
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	vector<pair<int, int> > Bar;
	vector<int> Razer;
	stack<int> start_point;
	string input;
	int length, Bar_cnt = 0, Razer_cnt = 0, cnt = 0;

	cin >> input;
	length = input.length();
	for (int i = 0; i < length; i++)
	{
		if (input[i] == '(')
		{
			if (input[i + 1] == ')')
			{
				Razer.push_back(i);
				Razer_cnt++;
				i = i + 1;
			}
			else // '('
				start_point.push(i);
		}
		else // ')'
		{
			Bar.push_back(make_pair(start_point.top(), i));
			Bar_cnt++;
			start_point.pop();
		}
	}
	for (int i = 0; i < Bar_cnt; i++)
	{
		int inbound = 0;
		for (int j = 0; j < Razer_cnt; j++)
		{
			if (Bar[i].first <= Razer[j] && Razer[j] <= Bar[i].second)
				inbound++;
		}
		cnt = cnt + inbound + 1;
	}
	cout << cnt;
	return 0;
}
