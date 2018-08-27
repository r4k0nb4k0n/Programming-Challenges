#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int N;
	string s;
	bool isVPS;

	cin >> N;
	while (N--)
	{
		stack<char> PS;
		isVPS = true;
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
				PS.push(s[i]);
			else
			{
				if (PS.empty())
				{
					isVPS = false;
					break;
				}
				else
					PS.pop();
			}
		}
		if (!PS.empty())
			cout << "NO\n";
		else
		{
			if (isVPS)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}
