#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	stack<char> str1, str2;
	string s;
	char temp;
	int N=0; // Initialized because this will be used for indexing.

	cin >> s;

	while (s[N] != '\0')
	{
		str1.push(s[N]);
		N++;
	}

	cin >> N; //Get the numbers of commands.
	
	while (N--) // Perform the command.
	{
		cin >> temp;
		if (temp == 'P') // Push the character.
		{
			cin >> temp;
			str1.push(temp);
		}
		else if (temp == 'L') // Move the cursor to the left.
		{
			if (!str1.empty())
			{
				temp = str1.top();
				str1.pop();
				str2.push(temp);
			}
		}
		else if (temp == 'D') // Move the cursor to the right.
		{
			if (!str2.empty())
			{
				temp = str2.top();
				str2.pop();
				str1.push(temp);
			}
		}
		else if (temp == 'B') // Delete and Backspace.
		{
			if (!str1.empty())
				str1.pop();
		}
	}

	while (!str1.empty())
	{
		temp = str1.top();
		str1.pop();
		str2.push(temp);
	}

	while (!str2.empty()) // OUTPUT.
	{
		cout << str2.top();
		str2.pop();
	}

	return 0;
}
