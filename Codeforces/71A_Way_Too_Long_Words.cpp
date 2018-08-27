#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	string input;
	cin >> n;
	while(n--){
		cin >> input;
		if(input.length() > 10){
			cout << input.at(0) << (input.length()-2) << input.at(input.length()-1) << "\n";
		}
		else{
			cout << input + "\n";
		}
	}
	return 0;
}