#include <iostream>
#include <string>
using namespace std;

int n;
string input;
int x=0;

int main(){
	cin >> n;
	while(n--){
		cin >> input;
		if(input.find('+')!=-1) x++;
		else if(input.find('-')!=-1) x--;
	}
	cout << x;
	return 0;
}
