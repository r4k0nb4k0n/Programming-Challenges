#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

int n;
string coordinate;

bool is_cartesian(string s)
{
	if(s.find('R') == 0 && s.find('R') == s.rfind('R') && s.find('C') == s.rfind('C') && s.find('C') - s.find('R') > 0) return true;
	return false;
}

string to_cartesian(string s)
{
	int pos = 0;
	while(isalpha(s[pos])) pos++;
	int r = 0, c = 0;
	for(int i=pos-1; i>=0; i--) c += (s[i] - 'A' + 1) * int(pow(('Z' - 'A' + 1), pos - 1 - i));
	r = stoi(s.substr(pos));
	return "R" + to_string(r) + "C" + to_string(c);
}

string to_alphabetic(string s)
{
	int r = stoi(s.substr(1, s.find('C')-1));
	int c = stoi(s.substr(s.find('C')+1));
	string ret = "";
	
	while(c > 0){
		char ch = (c % 26 == 0 ? 25 : c % 26 - 1) + 'A';
		ret = ch + ret;
		c /= 26;
	}
	
	ret = ret + to_string(r);
	
	return ret;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	while(n--){
		cin >> coordinate;
		if(is_cartesian(coordinate)) cout << to_alphabetic(coordinate) << "\n";
		else cout << to_cartesian(coordinate) << "\n";
	}
	return 0;
}