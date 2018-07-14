#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string input;
string output;

int main(){
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	for(int i=0; i<input.length(); i++){
		string vowels = "aoyeui";
		if(vowels.find(input[i]) == -1){
			output += ".";
			output += input[i];
		}	
	}
	cout << output;
	return 0;
}
