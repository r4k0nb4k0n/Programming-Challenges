#include <iostream>
#include <string>
using namespace std;

string input;
char delim;

int main(){
	cin >> input;
	string copy = input;
	delim = '0';
	auto i = 0;
	auto pos = copy.find(delim);
	while(pos != string::npos){
		if(copy.substr(i, pos-i).length() >= 7){
			cout << "YES";
			return 0;
		}
		i = ++pos;
		pos = copy.find(delim, pos);

		if(pos == string::npos){
			if(copy.substr(i, copy.length()).length() >= 7){
				cout << "YES";
				return 0;
			}
		}
	}
	delim = '1';
	i = 0;
	pos= copy.find(delim);
	while(pos != string::npos){
		if(copy.substr(i, pos-i).length() >= 7){
			cout << "YES";
			return 0;
		}
		i = ++pos;
		pos = copy.find(delim, pos);

		if(pos == string::npos){
			if(copy.substr(i, copy.length()).length() >= 7){
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}
